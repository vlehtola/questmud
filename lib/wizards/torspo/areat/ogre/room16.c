inherit "room/room";

reset(arg) {

  if(arg) { return; }
  add_exit("east", "/wizards/torspo/areat/ogre/room15.c");

   short_desc = "Fortress";
  long_desc = "It looks like there is no living thing in this tiny alley. Heaps of\n"+
              "half-eaten corpses are lying around here and the smell is disgusting.\n"+
              "Many small flies and rats seem to enjoy a good meal on several carcasses.\n"+
              "To your west is the tall wall of the fortress. No hope to get over it.\n";
  items = allocate(4);
  items[0] = "corpses";
  items[1] = "Different carcasses are lying apart here";
  items[2] = "wall";
  items[3] = "A well-made wooden fortress wall blocks the way to the west. It is impossible\n"+
             "to climb over it";
}
