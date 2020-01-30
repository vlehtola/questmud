inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc = "Jail\n";
  long_desc = "Congratulations, you have made your way to jail.\n";
  set_light(3);
  set_not_out(1);
  property = allocate(4);
  property[0] = "no_summon";
  property[1] = "no_kill";
  property[2] = "no_skill";
  property[3] = "no_spell";
}
init() {
::init();
  add_action("quit","quit");
}
  quit() {
  write("You can't quit while in jail.\n");
  return 1;
}

