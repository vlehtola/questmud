inherit "room/room";

reset(status arg) {
  if(arg) return;
  add_exit("north","/wizards/ozmala/areat/wine-cellar/rooms/room8");
  add_exit("east","/wizards/ozmala/areat/wine-cellar/rooms/room9");
  add_exit("south","/wizards/ozmala/areat/wine-cellar/rooms/room12");
  short_desc = "shotdesc";
  long_desc = "Long desc.\n"; 
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}
