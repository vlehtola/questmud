inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/dav1a1");
  add_exit("east","wizards/nalle/jerusalem/dav1a3");
  add_exit("south","wizards/nalle/jerusalem/vd8");
  short_desc = "South from David's Tower";
  long_desc =
"You are now in the southern part of the area surrounding\n" +
"David's Tower, a huge tower built of chalkstone, marble\n" +
"silver and gold. Cobblestoned paths go to the west and to\n" +
"east, probably leading to the back side of the tower where\n" +
"the entry must be. \n";
}
