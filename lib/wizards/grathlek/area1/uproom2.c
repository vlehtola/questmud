inherit "room/room"; 
 
 
reset(arg) {
  add_exit("east","/wizards/grathlek/area1/uproom3.c");
  add_exit("south","/wizards/grathlek/area1/uproom1.c");  
  
  short_desc = "The Towers Corridor leads east and south";
  long_desc = "This room has a Magical glow which grows to east.\n"+ 
              "This corridor shimmers more than any other room this\n"+
              "far away.\n";
              
               
 

}
