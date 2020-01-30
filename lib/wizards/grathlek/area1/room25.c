inherit "room/room";
 
 
reset(arg) {
  add_exit("northeast","/wizards/grathlek/area1/room24.c");
  add_exit("west","/wizards/grathlek/area1/room26.c");
 
  
  short_desc = "Path goes northeast and west.";
  long_desc = "The temple shimmers in strange light. Dark forest\n"+
              "is against the temple. But even the darkness in the \n"+
              "forest faint's away from the strange light.\n"; 

}
