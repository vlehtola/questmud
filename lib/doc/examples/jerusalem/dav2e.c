inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("east","wizards/nalle/jerusalem/dav2d");
  add_exit("south","wizards/nalle/jerusalem/dav2f");
  short_desc = "Inside David's Tower, Guards' Quarters";
  long_desc =
"There are a few beds here, they seem fairly comfortable\n" +
"and neat. Beside the beds there are small tables and racks\n" +
"on which the guards keep their weapons and other equipment.\n" +
"You may continue upwards to the south or back downwards to\n" +
"the east.\n";
}

