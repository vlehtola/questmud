inherit "room/room";
 
 
reset(arg) {
  add_exit("path","/wizards/grathlek/area1/room1.c");
  add_exit("north","out: 151 91");
  add_exit("south","out: 151 91");
  add_exit("west","out: 151 91");
  add_exit("east","out: 151 91");
 
  
  short_desc = "Path leading deeper in the forest.";
  long_desc = "There is a small path leading deeper in to the forest.\n"+
	      "The path it lit by some strange light coming from the forest.\n";

}
 
