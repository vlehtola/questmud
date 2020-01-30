inherit "room/room";
 
 
reset(arg) {
  add_exit("north","/wizards/grathlek/area1/room2.c");
  add_exit("southeast","/wizards/grathlek/area1/room26.c");
 
  
  short_desc = "Path goes southeast and north.";
  long_desc = "The temple shimmers in strange light. Dark forest\n"+
              "is against the temple. But even the darkness in the \n"+
              "forest faint's away from the strange light.\n"; 
}
