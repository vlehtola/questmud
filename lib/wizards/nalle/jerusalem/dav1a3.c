inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/dav1a2");
  add_exit("north","wizards/nalle/jerusalem/dav1b3");
  short_desc = "Southeast from David's Tower";
  long_desc =
"You are now in the southeastern part of the area surrounding\n" +
"David's Tower, a huge tower built of chalkstone, marble\n" +
"silver and gold. A cobblestoned path goes to the west and to\n" +
"the the north. \n";
}
