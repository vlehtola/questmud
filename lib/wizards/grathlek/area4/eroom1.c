inherit "room/room";
 
 
reset(arg) {
  add_exit("out","?");
  add_exit("southwest","/wizards/grathlek/area4/eroom2.c");
  set_light(2);
 
  short_desc = "In the entrance of a cave.";
  long_desc = "You stand in the entrance of a cave\n"+
              "where the red light glows dimly on the walls.\n"+
              "There might be something mean and evil near.\n"+
              "An old sign stands here.\n";
  
  items = allocate(4);
    items[0] = "sign";
    items[1] = "Welcome to the Demonic cave.";

}
