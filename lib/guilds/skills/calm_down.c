get_time() {
  return 1;
}
ep_cost() {
  return 20;
}
query_type() { return "neutral"; }

resolve_skill() {
  write("You put your hands on your head and tell yourself to calm down.\n");
  this_player()->end_berserk();
  return 1;
}

fail_skill() {
  write("You fail to calm down.\n");
  say(this_player()->query_name()+" fails to stop "+
	this_player()->query_possessive()+" madness!\n");
  return 1;
}
