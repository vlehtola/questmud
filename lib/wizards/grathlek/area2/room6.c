inherit "room/room";
 
 
reset(arg) {

  add_exit("east","/wizards/grathlek/area2/roomc.c");
  add_exit("west","/wizards/grathlek/area2/room5.c");
  set_light(1);
  
  short_desc = "In the main street of Tristram.";
  long_desc = "You are standing on the main street of Tristram.\n"+
              "You feel strongly an evils presense in this town.\n"+
              "Street is light whit street lamps.\n";
}
