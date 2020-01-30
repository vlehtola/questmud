#define SKILLDIR "/guilds/skills/"

int time, rounds_left;
string skill, target, arg, skill_name;
object who;
drop() { return 1; }

start_skill(str, object ob) {
  string word;
  int time,agility,tmp;
  who = ob;
  if(!who) { who=this_player(); }

  if(sscanf(str,"%s at %s", skill, target) != 2)
    skill = str;

  if (!who->query_skills(skill)) {
    tell_object(who, "You don't know such a skill.\n");
    interrupt_skill();
    return 0;
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
  /* rundissa 2 sekkaa (joku bugaa) */
  //time = time * 2;
  if(call_other(SKILLDIR+""+skill+".c", "query_type") == "offensive") {
  tell_object(who,"You start concentrating on the offensive skill.\n");
  tell_room(environment(who), who->query_name()+" starts concentrating on the offensive skill.\n");
  } else {
  tell_room(environment(who), who->query_name()+" starts concentrating on the skill.\n");
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
  rounds_left = time;
  write_skill();
  return 1;
}

write_skill() {
	int i;
	if(rounds_left == 0) {
	resolve_skill();
	return 1;
    }
    tell_object(who,capitalize(skill)+": ");
    while (i < rounds_left) { i++; tell_object(who,"#"); }
    tell_object(who,"\n");
    rounds_left--;
    call_out("write_skill", 1);
}



get_ep_cost(string arg) {
  string word;
  int pros, cost, endurance;
  while(sscanf(arg, "%s %s", arg, word) == 2) {
    arg = arg +"_"+ word;
  }
  if(file_size(SKILLDIR+arg+".c") == -1) {
    return 0;
  }
  pros = call_other(SKILLDIR+arg, "ep_cost");
  cost = who->query_max_ep() * pros / 100;

  if(cost) {
    endurance = who->query_skills("endurance");
    cost -= endurance / 15;
    if(cost > 20) cost = 20 + ( (cost-20) * (100-endurance/5) /100 );
    if(cost < 1) cost = 1;
  }


  return cost;
}

resolve_skill() {
  object ob;
  string tmp, extra_str;
  int cost;

  who->lited("You are prepared to do the skill."); tell_object(who,"\n");
  cost = get_ep_cost(skill);
  if(who->query_ep() < cost) {
    tell_object(who,"You don't have enough strength to complete this skill.\n");
    interrupt_skill();
    return 1;
  }
  who->reduce_ep(cost);
  /* Fail or not. (2x check for suffeli) */
  if (who->query_skills(skill_name) > random(110) ||
        who->query_skills(skill_name) > random(110)) {
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
