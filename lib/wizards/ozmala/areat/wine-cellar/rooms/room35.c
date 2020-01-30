inherit "room/room";

reset(status arg) {
  if(arg) return;
  add_exit("northwest","/wizards/ozmala/areat/wine-cellar/rooms/room36");
  add_exit("southeast","/wizards/ozmala/areat/wine-cellar/rooms/room34");
  short_desc = "shotdesc";
  long_desc = "Long desc.\n"; 
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}
