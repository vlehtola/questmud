inherit "room/room";
 
 
reset(arg) {
  add_exit("east","/wizards/grathlek/area1/room10.c");
  add_exit("west","/wizards/grathlek/area1/room8.c");
 
  
  short_desc = "Path goes east and west.";
  long_desc = "The temple shimmers in strange light. Dark forest\n"+
              "is against the temple. But even the darkness in the \n"+
              "forest faint's away from the strange light.\n"; 
 

}
