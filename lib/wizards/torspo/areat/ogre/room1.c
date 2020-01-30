inherit "room/room";

reset(arg) {
  if(arg) { return; }
  add_exit("north", "/wizards/torspo/areat/ogre/room14.c");
  add_exit("east", "/wizards/torspo/areat/ogre/room10.c");
  add_exit("west", "/wizards/torspo/areat/ogre/room2.c");
  add_exit("south", "out: 107 126");
  short_desc = "Fortress entrance";
  long_desc = "This is the entrance to a fortress. Walls of the fortress are made of\n"+
              "thick logs covered with moss and it seems that they are made by very\n"+
              "strong creatures. To the west lies a dark forest, and far to your east\n"+
              "a field where can be seen some large humanoids practicing their\n"+
              "battle skills. To north is the gate to the fortress.\n";
}

