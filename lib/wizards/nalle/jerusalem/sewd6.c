inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/sewc6");
  add_exit("east","wizards/nalle/jerusalem/sewe6");
  short_desc = "The sewers of Jerusalem";
  long_desc =
"You are now somewhere in the sewers of Jerusalem. The smell\n" +
"is horrible and all kinds of little creatures are running around\n" +
"the floor, occasionally climbing up your feet and into your trousers.\n"+
"You think you hear some voices from the west.\n";

  set_water(2);
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/sewmap");
   return 1;
}
