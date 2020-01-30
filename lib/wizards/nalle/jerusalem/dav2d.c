inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/dav2e");
  add_exit("south","wizards/nalle/jerusalem/dav2c");
  short_desc = "Inside David's Tower";
  long_desc =
"To your surprise, now as you have gotten quite far up\n" +
"the spiral in David's Tower, the amount of luxuries seems\n" +
"to decrease. Perhaps it is common to have a beautiful entry\n" +
"which can be seen by visitors, but modest quarters for the\n" +
"owners of the residence in this culture.\n";
}

