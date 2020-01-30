inherit "room/room";  

reset(arg) {
  add_exit("up","/wizards/devil/area/huoneet/r49.c");
  add_exit("north","/wizards/devil/area/huoneet/r59.c");
  add_exit("west","/wizards/devil/area/huoneet/r53.c");

  short_desc = "Small aisle in the back of the temple";
  long_desc = "This aisle is leading you to the back of the temple. The aisle was maybe used\n"+
                "by the staff that served in here because aisle is regular and there are\n"+
                "not unusual things like paintings on the wall. There are some small\n"+
                "stairs on the eastern wall leading upwards to the next floor.\n";
}
