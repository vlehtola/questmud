inherit "room/room";

reset(arg) {
  if(arg) {return; }
  add_exit("south", "/wizards/torspo/areat/gnomes/hills02.c");
  add_exit("north", "/wizards/torspo/areat/gnomes/hills07.c");
  short_desc = "Grassy hills";
  long_desc = "The path starts to go up to the mountains on its way to north. Smoke\n"+
              "drifts up from the north. There might be some settlement over there.\n"+
              "You wonder who would live in such cold and barren place as this is.\n";
}
