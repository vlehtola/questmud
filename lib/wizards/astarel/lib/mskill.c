#define SKILLDIR "/guilds/skills/"

string target, skill, file;

start_skill(sk, trg) {
  string tmp;
  int time,agility;
  target = lower_case(trg);
  file = lower_case(sk);
  while (sscanf(file,"%s %s", file, tmp) == 2) {
    file = file+"_"+tmp;
  }
  skill = lower_case(sk);
  if(!file) { file = skill; }
  if (!skill) { interrupt_skill(); }
  time = call_other(SKILLDIR + file, "get_time");
  time = time * 2;
  agility =this_player()->query_skills("agility");
  if(agility) {
    time -= time * (agility-random(3)) / 200;
  }
  call_out("resolve_skill", time*2);
  if(call_other(SKILLDIR+""+file+".c", "query_type") == "offensive") {
          say(this_player()->query_name()+" starts concentrating on the offensive skill.\n"); }
          else { say(this_player()->query_name()+" starts concentrating on the  skill.\n"); }

  return 1;
}

resolve_skill() {
  object ob;
  ob = present(target, environment(this_player()));
  if (!ob) {
    interrupt_skill(1);
    return 0;
  }
//Changed 'ob' to 'target' in call_other -- 201003 Rag
//Trying to fix monsters that stop fighting
  if(this_player()->query_skills(skill) > random(101)) {
    call_other(SKILLDIR + file, "resolve_skill", target, this_player());
  } else {
    call_other(SKILLDIR + file, "fail_skill", target, this_player());
  }
  interrupt_skill(1);
  return 1;
}

interrupt_skill(arg) {
  remove_call_out("resolve_skill");
  if(!arg) log_file("MSKILL", this_player()->short()+" stopped "+skill+" at "
        +target+".("+file+") Prev_ob: "+file_name(previous_object())+"\n", 1);
  destruct(this_object());
  return 1;
}
