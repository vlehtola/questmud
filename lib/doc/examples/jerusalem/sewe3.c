inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/sewe2");
  add_exit("south","wizards/nalle/jerusalem/sewe4");
  add_exit("west","wizards/nalle/jerusalem/sewd3");
  short_desc = "The sewers of Jerusalem";
  long_desc =
"This is the 'Cloaca Maxima', a sewage system built by\n" +
"the Duranghomians in an attempt to destroy diseases like the plague.\n" +
"Your surroundings are revolting. Peculiar looking slime and \n" +
"various types of fungi cover the humid rock walls. A very unpleasant\n" +
"odour has developped here in the course of time and this seems\n" +
"to be the ideal home for quite a number of rats and other similar\n" +
"rodents. You think you must be somewhere under the El Attar street.\n";

  set_water(3);
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

