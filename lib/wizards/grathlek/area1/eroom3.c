inherit "room/room";
 
 
reset(arg) {
  
  add_exit("east","/wizards/grathlek/area1/eroom4.c");  
  add_exit("west","/wizards/grathlek/area1/eroom2.c");
/*  add_exit("north", "/world/cleric/unpain/entrance"); */
  short_desc = "A crossing in the shimmering hallway";
  long_desc = "Walls of the hallway shimmers in stranger\n"+
              "light it seems to that light is all over\n"+
              "this temple. There is a corridor leading to the\n"+
	      "north, but the main hallway leads east and west.\n";

}

