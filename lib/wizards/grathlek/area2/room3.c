inherit "room/room";
 
 
reset(arg) {
  
  add_exit("east","/wizards/grathlek/area2/room4.c");   
  add_exit("west","/wizards/grathlek/area2/room2.c");
  
  short_desc = "On the road to Tristram.";
  long_desc = "The road leads to Tristram. You can\n"+
              "see light coming from the town of\n"+
              "Tristram.\n";
}
