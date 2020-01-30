inherit "room/room";

reset(status arg) {
  if(arg) return;
  add_exit("north","/wizards/ozmala/areat/wine-cellar/rooms/room12");
  add_exit("west","/wizards/ozmala/areat/wine-cellar/rooms/room26");
  add_exit("south","/wizards/ozmala/areat/wine-cellar/rooms/room24");
  short_desc = "shotdesc";
  long_desc = "Long desc.\n"; 
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}
