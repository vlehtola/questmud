get_time(str) {
  return 10;
}
ep_cost() { return 30; }
query_type() { return "neutral"; }

resolve_skill(target) {

// pure berserk copypasted skill. disabled by angry Celtron 28.4.2004. 
// not to be returned in game without Celtron's approval.

  write("This skill has been disabled for further notice.\n");
  return 1;

  if(this_player()->query_berserk()) {
    write("You cannot use focus elements now.\n");
  return 1;
}
  if(this_player()->query_defend()) {
   write("You cannot use focus elements now.\n");
    return 1;
}
  clone_object("/guilds/skill_obj/focus_elements_ob")->start(this_player());
  write("You focus your elements!\n");
  say(this_player()->query_name()+" focuses elements of fire, ice and thunder!\n");
  return 1;
}
fail_skill() {
  write("You fail to focus your powers.\n");
  say(this_player()->query_name()+" tries hard, but can't focus "+
    this_player()->query_possessive()+" powers of fire,ice and thunder.\n");
  return 1;
}
