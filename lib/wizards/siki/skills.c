#define SKILLS_DIR "/wizards/siki/skills/"
static int skill_coming = 0;
static int skill_rounds_left = 0;
static string skill_name = "";
static string skill = "";
static string skill_param = "";
static string skill_target = "";

private mapping skills = ([ ]);

drop() { return 1; }

mixed get_value(string name, string value) {
	switch (value) {
	case "type": return SKILLS_DIR+""+name+""->query_skill_type();
	case "trained": return this_player()->query_skills(name);
	case "usagetime": return SKILLS_DIR+""+name+""->query_usagetime();
	case "cost": return get_ep_cost(name);
	case "affecting_stats": return SKILLS_DIR+""+name+""->query_affecting_stats();
	case "affecting_skills": return SKILLS_DIR+""+name+""->query_affecting_skills();
	case "description": return SKILLS_DIR+""+name+""->query_description();
	}
}

int is_skill_coming() {
	return skill_coming;
}

void set_skill_coming(int x) {
	skill_coming = x;
}

void stop_skill() {
	skill_coming = x;
	say(this_player()->query_name()+" breaks "+this_player()->query_objective()+" concentration.\n");
	write("You break your concentration.\n");
	return 1;
}

void do_skills() {
	int i = 0;
	int chance;
	if(!skill_coming) return;
	if(skill_rounds_left == 0) {
	 set_skill_coming(0);
      if(skills[skill_name]->query_type() == SS_OFFENSIVE) {
	  if(!skill_target && !this_body()->query_target()) {
	   write("Use at what?\n");
	   return;
	  }
       if(environment(this_body()) != environment(skill_target)) {
	   write("There's no '"+skill_target->query_name()+"' here.\n");
	   return;
	  }
	  if(!living(skill_target)) {
 	   write("That is not a valid offensive target.\n");
	   return;
	  }
	  if(skill_target == this_body()) {
	   write("How about typing suicide?\n");
	   return;
	  }
	  if(skill_target->query_ghost()) {
	   write("But '"+skill_target->query_name()+"' is a ghost!\n");
	   return;
	  }
	   chance = random(100-this_body()->query_skill(skill_name,"trained"));
	   if(chance < 50) {
	    write("%^BOLD%^You are done with the skill.%^RESET%^\n");
            NEW_SKILL_D->do_skill_ext(skill_name,skill_target,skill_param);
	   } else {
	    this_body()->simple_action("%^BOLD%^$N $vfail the skill.%^RESET%^");
	   }
	   this_body()->set_fp(this_body()->query_fp()-this_body()->query_skill(skill_name,"cost"));
           this_body()->do_beat();
	 } else
         if(skills[skill_name]->query_type()==SS_NEUTRAL ||
	    skills[skill_name]->query_type()==SS_HEAL) {
	  if(!skill_target) skill_target = this_object();
	  chance = random(100 - this_body()->query_skill(skill_name,"trained"));
	  if(chance < 50) {
	    write("%^BOLD%^You are done with the skill.%^RESET%^\n");
        NEW_SKILL_D->do_skill_ext(skill_name,skill_target,skill_param);
	  } else {
	    this_body()->simple_action("%^BOLD%^$N $vfail the skill.%^RESET%^");
	  }
	  this_body()->set_fp(this_body()->query_fp()-this_body()->query_skill(skill_name,"cost"));
          this_body()->do_beat();
	 }
	} else {
	 write(skill_name+": ");
	while (i < skill_rounds_left) {i++; write ("#"); }
	 write("\n");
	 call_out( (:do_skills:), 4);
	}
	skill_rounds_left--;
}

void start_skill(string str) {
  string word;
  int time,agility,tmp;
  string tmp1, tmp2, tmp3;
  if(sscanf(str,"%s at %s", tmp1, tmp2) == 2) {
  skill_name = tmp1;
  skill_target = tmp2;
  }
  if(sscanf(str, "%s at %s with %s", tmp1, tmp2, tmp3) == 3) {
  skill_name = tmp1;
  skill_target = tmp2;
  skill_param = tmp3;
  }
  skill = skill_name
  if (!get_value(skill,"trained")) {
    write("You don't know such a skill.\n");
    interrupt_skill();
    return 0;
  }
  while(sscanf(skill_name, "%s %s", skill_name, word) == 2) {
    skill_name = skill_name +"_"+ word;
  }
  if (!skill_name) {
    write("ERROR! No skill to resolve.\n");
    interrupt_skill();
    return 1;
  }
  time = get_value(skill_name, "usagetime");
  if(time == 0) {
    write("This skill is automatically in use..\n");
    return 1;
  }
  if (this_player()->query_stunned()) {
  write("You are stunned and unable to use skills.\n");
  interrupt_skill();
  return 1;
  }
  if(this_player()->query_ep() < get_value(skill_name, "cost")) {
  write("You don't have enough strength to start this skill.\n");
  interrupt_skill();
  return 1;
  }
  write("Skill chance: "+get_skill_chance(skill)+".\n");
  switch(get_value(skill_name,"type") {
  case "offensive":
  write("You start concentrating on the offensive skill.\n");
  say(this_player()->query_name()+" starts concentrating on the offensive skill.\n");
  break;
  case "neutral":
  write("You start concentrating on the skill.\n");
  say(this_player()->query_name()+" starts concentrating on the skill.\n");
  break;
  case "witchcraft":
  write("You start concentrating on the witchcraft.\n");
  say(this_player()->query_name()+" starts concentrating on the witchcraft.\n");
  break;
  default:
  write("You start concentratigng on the skill.\n");
  say(this_player()->query_name()+" starts concentrating on the skill.\n");
  }
  if(this_player()->query_tester() || this_player()->query_wiz())
  write("Skill duration: "+time+" rounds.\n");
  agility = this_player()->query_skills("agility");
  if(agility) {
  tmp = time;
  time -= time * (agility-random(3)) / 200;
  if(tmp != time)
  write("Your agility helps you to perform the skill in less time.\n");
  }
  skill_rounds_left = time;
  call_out("write_skill", 2);
  return 1;
}

write_skill() {
        int i;
        if(rounds_left == 0) {
        resolve_skill();
        return 1;
    }
    write(capitalize(skill)+": ");
    while (i < rounds_left) { i++; write("#"); }
    write("\n");
    rounds_left--;
    call_out("write_skill", 2);
}
interrupt_skill() {
  remove_call_out("write_skill");
  if (this_object()) {
  destruct(this_object());
  }
  return 1;
}

get_ep_cost(string arg) {
  string word;
  int pros, cost, endurance;
  while(sscanf(arg, "%s %s", arg, word) == 2) {
    arg = arg +"_"+ word;
  }
  if(file_size(SKILLS_DIR+arg+".c") == -1) {
    return 0;
  }
  pros = call_other(SKILLS_DIR+arg, "ep_cost");
  cost = this_player()->query_max_ep() * pros / 100;
  if(cost) {
    endurance = this_player()->query_skills("endurance");
    cost -= endurance / 15;
    if(cost > 20) cost = 20 + ( (cost-20) * (100-endurance/5) /100 );
    if(cost < 1) cost = 1;
  }
  return cost;
}
//Get the chance to succesfully use the skill
get_skill_chance(string arg) {
	int chance, i, x;
	i = this_player()->query_skills(arg)*10;
    x = this_player()->query_dex()/5;
    chance = i+x;
    if(chance > 1000)chance=1000;
    return chance/10;
}
