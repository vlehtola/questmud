inherit "room/room";
 
 
reset(arg) {
  add_exit("northeast","/wizards/grathlek/area1/room4.c");
  add_exit("south","/wizards/grathlek/area1/room2.c");
 
  
  short_desc = "Path goes northeast and south.";
  long_desc = "The temple shimmers in strange light. Dark forest\n"+
              "is against the temple. But even the darkness in the\n"+
              "forest faint's away from the strange light.\n"; 
}
