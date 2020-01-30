inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc = "A dark tunnel";
  long_desc = "You are standing in a dark tunnel, which is carved into rock.\n";
  add_exit("west", "/wizards/celtron/maze/necro/2");
  add_exit("exit", "/wizards/celtron/maze/hall");
}


