inherit "room/room";
 
 
reset(arg) {

  add_exit("east","/wizards/grathlek/area2/roome.c");
  add_exit("west","/wizards/grathlek/area2/rooms.c");
  set_light(1);
    
  short_desc = "In the cathedral street of Tristram.";
  long_desc = "You are standing on the cathedral street of Tristram.\n"+
              "You feel strongly an evils presense in this town.\n"+
              "Street is light whit street lamps.\n";
}
