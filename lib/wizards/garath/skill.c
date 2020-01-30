#define SKILLDIR "/guilds/skills/"
#define MASTERY_D "/daemons/mastery_d"
#define COMBAT_D "/daemons/combat"

int time, rounds_left, start;
string skill, target, arg, skill_name;
object who;
drop() { return 1; }

start_skill(str, object ob) {
  string word,skilltmp,wordtmp;
  int time,agility,tmp;
  string estimation;
  who = ob;
  if(!who) { who=this_player(); }

  if(sscanf(str,"%s at %s", skill, target) != 2) {
    skill = str;

// Added by Garath, 24.10.05
// If skilluser is in combat and no target defined - target will be automatically
// defined in here by query_attacker() function. Also checked that the user is
// in the same environment() and if the skill is offensive. :)
    skilltmp = regreplace(skill, " ", "_", 1);
    if(who->query_attacker() && ( environment(who->query_attacker()) == environment(who) ) && ( call_other(SKILLDIR+""+skilltmp+".c", "query_type") == "offensive" ) ) {
      target = who->query_attacker()->query_name();
    }
  } 

  if (!who->query_skills(skill)) {
    tell_object(who, "You don't know such a skill.\n");
    interrupt_skill();
    return 0;
  }
   switch (who->query_skills(skill)) {
    case   0..  4: estimation = "almost impossible"; break;
    case   5.. 10: estimation = "rather impossible"; break;
    case  11.. 14: estimation = "very small"; break;
    case  15.. 19: estimation = "rather small"; break;
    case  20.. 24: estimation = "reasonably small"; break;
    case  25.. 29: estimation = "small"; break;
    case  30.. 39: estimation = "almost average"; break;
    case  40.. 44: estimation = "nearly average"; break;
    case  45.. 54: estimation = "average"; break;
    case  55.. 59: estimation = "above average"; break;
    case  60.. 69: estimation = "reasonably fair"; break;
    case  70.. 79: estimation = "fair"; break;
    case  80.. 84: estimation = "rather good"; break;
    case  85.. 89: estimation = "good"; break;
    case  90.. 94: estimation = "very good"; break;
    case  95.. 99: estimation = "excellent"; break;
    case 100..999: estimation = "superb"; break;
    default: estimation = "some kind of a";
 }
  skill_name = skill;
  while(sscanf(skill, "%s %s", skill, word) == 2) {
    skill = skill +"_"+ word;
  }
  if(file_size(SKILLDIR+skill+".c") == -1) {
    tell_object(who, "That skill is automatically in use.\n");
    interrupt_skill();
    return 1;
  }
  if (!skill) {
    tell_object(who, "ERROR! No skill to resolve.\n");
    interrupt_skill();
    return 1;
  }
  time = call_other(SKILLDIR + skill, "get_time", 0);
  if(!time) {
    tell_object(who, "No such skill.\n");
    return 1;
  }
  if (who->query_stunned()) {
      tell_object(who,"You are stunned and unable to use skills.\n");
      interrupt_skill();
      return 1;
  }
  /* rundissa 2 sekkaa */
  time = time * 2;
  if(call_other(SKILLDIR+""+skill+".c", "query_type") == "offensive") {
  tell_object(who,"You start concentrating on the offensive skill.\n");
  tell_room(environment(who), who->query_name()+" starts concentrating on the offensive skill.\n", ({ who, }));
  } else {
  tell_room(environment(who), who->query_name()+" starts concentrating on the skill.\n", ({ who, }));
  tell_object(who,"You start concentrating on the skill.\n");
  }
  if(who->query_tester() || who->query_wiz())
        tell_object(who,"Skill duration: "+time+" rounds.\n");
  agility = who->query_skills("agility");
  if(agility) {
   tmp = time;
   time -= time * (agility-random(3)) / 200;
   if(tmp != time)
   tell_object(who,"Your agility helps you to perform the skill in less time.\n");
  }
  tell_object(who,"You think that there is a "+estimation+" chance of succeeding.\n");
  rounds_left = time;
  start = 1;
  write_skill();
  return 1;
}

write_skill() {
    int i;
    if(rounds_left == 0) {
      resolve_skill();
      return 1;
    }
// Removed by Rag, 25.2.04 due to abuse
// Added ability and you can't see this for the first time -- Rag
    if ( who->query_ability("durationsense") && !start ) {
      tell_object(who,capitalize(skill)+": ");
      while (i < rounds_left) { i++; tell_object(who,"#"); }
      tell_object(who,"\n");
    }

    rounds_left--;
    start = 0;
    call_out("write_skill", 1);
}



get_ep_cost(string arg, object ob) {
  string word;
  int pros, cost, endurance;
  object o;
  while(sscanf(arg, "%s %s", arg, word) == 2) {
    arg = arg +"_"+ word;
  }
  if(file_size(SKILLDIR+arg+".c") == -1) {
    return 0;
  }
  o = ob;
  if(!o) o = this_player();
  pros = call_other(SKILLDIR+arg, "ep_cost");
  cost = o->query_max_ep() * pros / 100;

  if(cost) {
    if ( cost > 50 ) {
      cost = 50 + ( cost - 50 ) / 2;
    }
    endurance = o->query_skills("endurance");
    endurance += MASTERY_D->query_mastery("Offensive maneuvers",o)/2;
    cost -= endurance / 15;
    if(cost > 20) cost = 20 + ( (cost-20) * (100-endurance/5) /100 );
    if(cost < 1) cost = 1;
  }

  return cost;
}

resolve_skill() {
  object ob;
  string tmp, extra_str;
  int cost, dodge, parry;

  who->lited("You are prepared to do the skill."); tell_object(who,"\n");
  cost = get_ep_cost(skill,who);
  if(who->query_ep() < cost) {
    tell_object(who,"You don't have enough strength to complete this skill.\n");
    interrupt_skill();
    return 1;
  }
  who->reduce_ep(cost);
  /* Fail or not. (2x check for suffeli) */
  if (who->query_skills(skill_name) > random(110) ||
        who->query_skills(skill_name) > random(110)) {

    // give the target a chance to dodge or parry the skill. C 21102005
    if (target) ob = present(target, environment(who));
    if(call_other(SKILLDIR+""+skill+".c", "query_type") == "offensive" && ob && living(ob)) {      
      dodge = COMBAT_D->dodge_chance(ob);
      parry = COMBAT_D->parry_chance(ob);
      // less than 6% chance even with maxxed dodge 
      if(dodge > random(700)) {
        tell_object(who, ob->query_name()+" dodges your skill attempt!\n");
        tell_object(ob, "You dodge "+ob->query_name()+"'s skill attempt!\n");
	ob->attack_object(who);
        interrupt_skill();
        return 1;
      }
      if(parry > random(700)) {
        tell_object(who, ob->query_name()+" notices your skill attempt and parries it!\n");
        tell_object(ob, "You notice "+ob->query_name()+"'s skill attempt just in time to parry it!\n");
	ob->attack_object(who);
        interrupt_skill();
        return 1;
      }
    }

    call_other(SKILLDIR + skill, "resolve_skill", target, who);
  }
  else {
    call_other(SKILLDIR + skill, "fail_skill", target, who);
  }
  interrupt_skill();
  return 1;
}

interrupt_skill() {
  remove_call_out("write_skill");
  if (this_object()) {
  destruct(this_object());
  }
  return 1;
}
