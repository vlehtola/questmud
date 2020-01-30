inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/dav1c1");
  add_exit("south","wizards/nalle/jerusalem/dav1a1");
  short_desc = "West from David's Tower";
  long_desc =
"You are now in the western part of the area surrounding\n" +
"David's Tower, a huge tower built of chalkstone, marble\n" +
"silver and gold. The cobblestoned path you are on goes on\n" +
"to the north, and back to your south, where you came from.\n" +
"You cannot help admiring the superb carvings and items\n" +
"that decorate the walls of the tower.\n";
}
