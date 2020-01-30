inherit "room/room";

reset(status arg) {
  if(arg) return;
  add_exit("west","/wizards/ozmala/areat/wine-cellar/rooms/room40");
  add_exit("south","/wizards/ozmala/areat/wine-cellar/rooms/room38");
  short_desc = "shotdesc";
  long_desc = "Long desc.\n"; 
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}
