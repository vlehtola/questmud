get_time(str) {
  return 10;
}
ep_cost() { return 30; }

resolve_skill(target) {
  if(this_player()->query_defend()) {
    write("You cannot use berserk now.\n");
    return 1;
  }
  clone_object("/guilds/skill_obj/berserk_ob")->start(this_player());
  write("You SCREAM in rage!\n");
  say(this_player()->query_name()+" seems to get REALLY angry!\n");
  return 1;
}

fail_skill() {
  write("You fail to focus yourself.\n");
  say(this_player()->query_name()+" tries hard, but can't focus "+
    this_player()->query_possessive()+"self.\n");
  return 1;
}
