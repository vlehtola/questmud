inherit "room/room";
 
 
reset(arg) {

  add_exit("east","/wizards/grathlek/area2/room13.c"); 
  add_exit("west","/wizards/grathlek/area2/room11.c");
  set_light(0);
  
  short_desc = "In the dark street of Tristram.";
  long_desc = "You are standing on the dark street of Tristram.\n"+
              "You feel strongly an evils presense in this town.\n"+
              "The street lamp is broken.\n";
}
