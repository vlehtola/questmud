inherit "room/room";
 
 
reset(arg) {

  add_exit("east","/wizards/grathlek/area2/room12.c"); 
  add_exit("south","/wizards/grathlek/area2/roomc.c");
  add_exit("west","/wizards/grathlek/area2/room10.c");
  set_light(0);
  
  short_desc = "In the dark street of Tristram.";
  long_desc = "You are standing on the dark street of Tristram.\n"+
              "You feel strongly an evils presense in this town.\n"+
              "The street lamp is broken.\n";
}
