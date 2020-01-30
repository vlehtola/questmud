inherit "room/room";  
object monster;


reset(arg) {
  
  add_exit("west","/wizards/devil/area/huoneet/r52.c");
  add_exit("east","/wizards/devil/area/huoneet/r50.c");

  short_desc = "Small corridor under the ground";
  long_desc = "You are standing in the small corridor possibly under the huge temple.\n"+
             "Corridor is beaming a bit down to the darkness. Some raindrops are\n"+
             "dropping from the ceiling to the ground. The corridor is getting smaller\n"+   
             "with every step that you take into darkness. Some light can be seen coming\n"+
             "from west.\n";

}
