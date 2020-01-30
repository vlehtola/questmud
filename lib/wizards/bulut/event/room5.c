inherit "room/room";


reset(arg) {
  add_exit("north","/wizards/bulut/event/room6");
  add_exit("west","/wizards/bulut/event/room1");
  add_exit("south","/wizards/bulut/event/room4");

  short_desc = "Different plane";
  long_desc = "You can sense adrenaline all around you.\n";
               

  set_not_out(1);               /* Optional, explained previously */
  set_light(3);                 /* Optional, explained previously */



  property = allocate(1);
  property[0] = "no_summon";

}
                              