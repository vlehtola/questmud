inherit "room/room";

reset(status arg) {
  if(arg) return;
  add_exit("north","/wizards/ozmala/areat/wine-cellar/rooms/room3");
  add_exit("east","/wizards/ozmala/areat/wine-cellar/rooms/room5");
  add_exit("tele","/wizards/ozmala/areatele");
  short_desc = "shotdesc";
  long_desc = "Long desc.\n"; 
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}
