inherit "room/room";

reset(arg) {
call_other("/wizards/yodin/areas/island/virtual_map", "XX", 0);
  if(arg) return;
  add_exit("north", "/wizards/yodin/areas/island/virtual_map: 26 21");
  add_exit("southwest", "/wizards/yodin/areas/village/vh11.c");

  short_desc = "island entrance";
  long_desc = "kiva pikku saari.\n";
}

