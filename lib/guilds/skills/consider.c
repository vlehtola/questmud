get_time(str) {
  return 6;
}
query_type() { return "neutral"; }

ep_cost() { return 1; }
skill_limit(int i) {
  int skill;
  skill =this_player()->query_skills("consider");
  if(i>skill) {
    write("Your limited knowledge can't figure out everything about this ability.\n");
    i = skill;
  }
  return i;
}

resolve_skill(str) {
  int i,hp,lv;
  string n,txt;
  string tmp,tmp2;
  object target;
  tmp = "*********************************";
  tmp2 = ".................................";
  if(!str) {
    write("Use consider at who?\n");
    return 1;
  }
  target = present(str, environment(this_player()));
  if(!target || !living(target)) {
    write(str+" is not a valid target.\n");
    return 1;
  }
  write("Considering "+target->short()+":\n");
  i = skill_limit(target->query_hp() / 80+random(30)) / 3;
  if(i> strlen(tmp)) i = strlen(tmp);
  write("Hit Points: ["+extract(tmp,0,i)+extract(tmp2,0,strlen(tmp)-i)+"]\n");

  i = skill_limit(target->query_str()/6+target->query_wc()/3) *2/3;
  if(i> strlen(tmp)) i = strlen(tmp);
  write("Offense:    ["+extract(tmp,0,i)+extract(tmp2,0,strlen(tmp)-i)+"]\n");

  i = skill_limit(target->query_dex()/6+target->query_resists(0) /2) *2/3;
  if(i> strlen(tmp)) i = strlen(tmp);
  write("Defense:    ["+extract(tmp,0,i)+extract(tmp2,0,strlen(tmp)-i)+"]\n");
  return 1;
}

fail_skill(str) {
  if(!str) { write("Use consider at who?\n"); return 1; }
  write("You can't figure anything out of " + str + ".\n");
}
