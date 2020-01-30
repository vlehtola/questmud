inherit "room/room"; 
 
 
reset(arg) {
  add_exit("south","/wizards/grathlek/area1/uproom6.c");  
  add_exit("northeast","/wizards/grathlek/area1/uproom4.c");
  add_exit("northwest","/wizards/grathlek/area1/uproom3.c");
  
  short_desc = "The Towers Corridor leads southwest and west";
  long_desc = "This room has a Magical glow which grows to south.\n"+ 
              "This corridor shimmers more than any other room this\n"+
              "far away.\n";
              
               
 

}
