inherit "room/room";
 
 
reset(arg) {
  add_exit("east","/wizards/grathlek/area2/room19.c");
  add_exit("north","/wizards/grathlek/area2/room8.c");
  add_exit("west","/wizards/grathlek/area2/room17.c");
  set_light(1);
    
  short_desc = "In the cathedral street of Tristram.";
  long_desc = "You are standing on the cathedral street of Tristram.\n"+
              "You feel strongly an evils presense in this town.\n"+
              "Street is light whit street lamps.\n"; 
  items = allocate(4);
    items[0] = "sing"; 
    items[1] = "It reads:\n"+
               "Cathedral of Kahnduras is east from here\n";
}
