inherit "room/room";

reset(arg) {
  if(arg) { return; }
  add_exit("southeast", "/wizards/torspo/areat/gnomes/hills11.c");
  add_exit("northeast", "/wizards/torspo/areat/gnomes/hills21.c");

  short_desc = "Gnomish mountains";
  long_desc = "You are in the bottom of the narrow canyon. The mountains rise all around\n"+
              "you. No living thing is in sight but there are some footprints of wolves\n"+
              "on the ground. The snow has piled in the huge drifts in the upper parts of\n"
              "the mountain.\n"+
              "There's a sign standing on the ground.\n";
  items = allocate(2);
  items[0] = "sign";
  items[1] = "'Avoid loud voices, be alert in case of an avalanche'";
}
