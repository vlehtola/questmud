inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  add_exit("north", "/wizards/torspo/portal.c");
  add_exit("event", "/room/event_room.c");
  short_desc = "Wizroom";
  long_desc = "Room of Torspo the wiz. :)\n"; 
  property = allocate(1);
  property[0] = "no_summon";
}







