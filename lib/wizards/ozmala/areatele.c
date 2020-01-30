inherit "room/room";

reset(status arg) {
  if(arg) return;
  add_exit("up","/wizards/ozmala/workroom");
  add_exit("test","/wizards/ozmala/areat/area-testi/roomit/roomi1");
  add_exit("wine-cellar","/wizards/ozmala/areat/wine-cellar/rooms/room4");
  short_desc = "shotdesc";
  long_desc = "Area teleport room.\n"; 
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}
