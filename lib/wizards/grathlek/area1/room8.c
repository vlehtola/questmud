inherit "room/room";
 
 
reset(arg) {
  add_exit("south","/wizards/grathlek/area1/room14.c");
  add_exit("northwest","/wizards/grathlek/area1/room7.c");
 
  
  short_desc = "Path goes south and northwest.";
  long_desc = "The temple shimmers in strange light. Dark forest\n"+
              "is against the temple. But even the darkness in the \n"+
              "forest faint's away from the strange light.\n"; 
}
