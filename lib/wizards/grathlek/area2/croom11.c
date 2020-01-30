inherit "room/room";

 
reset(arg) {
  add_exit("east","/wizards/grathlek/area2/croom12.c");
  add_exit("west","/wizards/grathlek/area2/croom10.c");
  set_light(0); 
  
  short_desc = "In the dark cathedral.";
  long_desc = "You are standing on the corridors of.\n"+
              "the dark cathedral Kahnduras.\n"+
              "It's very dark and cold here.\n"; 
 

}
