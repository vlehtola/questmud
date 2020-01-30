#define RACE_D "/daemons/race_stats"

reset(arg) {
  if (arg) return;
  set_light(3);
}

query_property(string str) {
  switch(str) {
  case "no_summon": return 1;
  case "no_kill": return 1;
  default: return 1;
  }
}

init() {
    /* reset race stats */
  if(!this_player()->query_wiz())
    this_player()->set_race(); 

  add_action("info","info");
  add_action("select", "select");
  add_action("continu", "continue");
  add_action("kill", "kill");
}

query_not_out() { return 5; }

kill() {
  write("Not in here, shame on you!\n");
  return 1;
}

continu() {
  if (!this_player()->query_race()) {
    write("No race set. Please select one.\n");
    return 1;
  }
  write("Continuing character creation..\n");
  move_object(this_player(), "/world/special/traits");
  call_other("world/special/traits", "long");
  return 1;
}

long() {
    string str,tp,tp2,tmp;
    int i;
    str = get_dir("/data/races/");
    tmp = "                       ";
    write("This is the race selection room.\n");
    write("Commands: info <race>\n");
    write("          select <race>\n");
    write("\n");
    write("Available races:\n");
    while(i<sizeof(str)) {
      if(sscanf(str[i], "%s_%s", tp,tp2))
        str[i] = tp+" "+tp2;
      write(str[i]+extract(tmp,0,15-strlen(str[i])));
      i += 1;
      if(i/3*3 == i) write("\n");
    }
    write("\n");
    write("Type 'continue', if you are done.\n");
}    
short() {
    return "Race selection room";
}
query_infra(string str) {
  if(!str) return 3;
  str = lower_case(str);
  return RACE_D->query_race_stat(str, "infra");
}

get_stats(string race,string stat) {
  string tmp,file, str;
  str = race;
  if(!str) {
    return 0;
  }  
  while(sscanf(str,"%s %s",str,tmp) == 2) {
    str = str + "_" + tmp;
  }  
  file = "/data/races/"+str;
  if(file_size(file) == -1) {
    write("No such race.\n");  
    return 0;
  }

  switch(stat) {
  case "skill_max": return 90;
  case "spell_max": return 90;
  case "special": return 0;
  case "epr": stat = "hpr";
  }

  // normal ppl can't select nor see info about rebirth races
  if(RACE_D->query_race_stat(race, "rebirth") > this_player()->query_rebirth() && this_player()->query_wiz() < 2) {
    write("This race is usable only for rebirthing characters.\n");
    return 0;
  }

  return RACE_D->query_race_stat(race, stat);
}

info(string arg) {
  string file,tmp,str;
  object ob;
  if (!arg) { write("Usage: 'info [race]'\n"); return 1; }

  // normal ppl can't select nor see info about rebirth races
  if(RACE_D->query_race_stat(arg, "rebirth") > this_player()->query_rebirth() && this_player()->query_wiz() < 2) {
    write("This race is usable only for rebirthing characters.\n");
    return 1;
  }

  RACE_D->query_race_info(arg);
  return 1;
}

select(string str) {
  string file,tmp;
  object ob;
  if(!get_stats(str,"str")) return 1;
  this_player()->set_race(str,get_stats(str,"str"),get_stats(str,"dex"),
    get_stats(str,"con"),get_stats(str,"int"),get_stats(str,"wis"),
    get_stats(str,"size"), get_stats(str,"exp_rate"),
    get_stats(str,"skill_max"),get_stats(str,"spell_max"),get_stats(str,"special"),
    get_stats(str,"hpr"),get_stats(str,"spr"),get_stats(str,"epr"));
  write("Setting your race as " + capitalize(str) + ".\n");
  write("Type 'continue', if you are done with the race.\n");
  return 1;
}

update_race(string str) {
  if (str) { str = lower_case(str); }
  this_player()->update_race(str,get_stats(str,"str"),get_stats(str,"dex"),
    get_stats(str,"con"),get_stats(str,"int"),get_stats(str,"wis"),
    get_stats(str,"size"), get_stats(str,"exp_rate"),
    get_stats(str,"skill_max"),get_stats(str,"spell_max"),get_stats(str,"special"),
    get_stats(str,"hpr"),get_stats(str,"spr"),get_stats(str,"epr"));
}


