inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/dav1b1");
  add_exit("east","wizards/nalle/jerusalem/dav1a2");
  short_desc = "South-west from David's Tower";
  long_desc =
"You are now in the south-western part of the area surrounding\n" +
"David's Tower, a huge tower built of chalkstone, marble\n" +
"silver and gold. The cobblestoned path you are on goes on\n" +
"to the north, and obviously back to your east, where you\n" +
"came from.\n";
}
