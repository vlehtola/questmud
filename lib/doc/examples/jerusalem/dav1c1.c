inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("east","wizards/nalle/jerusalem/dav1c2");
  add_exit("south","wizards/nalle/jerusalem/dav1b1");
  short_desc = "North-west from David's Tower";
  long_desc =
"You are now in the north-western part of the area surrounding\n" +
"David's Tower, a huge tower built of chalkstone, marble\n" +
"silver and gold. The cobblestoned path you are on goes on\n" +
"to the east, where you think you can see the entrance to the\n" +
"tower, and of course back to the south, where you came from.\n";
}
