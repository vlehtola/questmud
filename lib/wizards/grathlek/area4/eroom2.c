inherit "room/room";
 
 
reset(arg) {
  add_exit("northeast","/wizards/grathlek/area4/eroom1.c");
  add_exit("southwest","/wizards/grathlek/area4/eroom3.c");
  set_light(2);
 
  short_desc = "In the red glowing cave.";
  long_desc = "This is a rocky and tight cave.\n"+
              "Red light shimmers creepy on the walls and\n"+
              "you can sense something evil near.\n"+
              "If you are a chicken you can still turn back.\n";
}
