reset() { }

short() { return "One exit: inn"; }

init() {
  add_action("move_out", "inn");
}

move_out() {
  write("Moving..\n");
  move_object(this_player(), "/world/city/inn");
  return 1;
}
