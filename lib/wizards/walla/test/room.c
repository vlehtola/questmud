inherit "room/room";
 
reset(arg) {
 
  add_exit("north","leblair2");
  short_desc = "In an underground lair";
  long_desc = "The room, that you have just entered!";
  property = allocate(4);
  property[0] = "no_kill";
  property[3] = "no_summon";
 }
