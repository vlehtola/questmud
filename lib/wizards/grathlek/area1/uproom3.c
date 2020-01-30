inherit "room/room"; 
 
 
reset(arg) {
  add_exit("east","/wizards/grathlek/area1/uproom4.c");
  add_exit("west","/wizards/grathlek/area1/uproom2.c");  
  add_exit("southeast","/wizards/grathlek/area1/uproom5.c");
  
  short_desc = "The Towers Corridor leads east, southeast and west";
  long_desc = "This room has a Magical glow which grows to southeast.\n"+ 
              "This corridor shimmers more than any other room this\n"+
              "far away.\n";
}
