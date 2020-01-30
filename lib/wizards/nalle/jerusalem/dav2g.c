inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/dav2f");
  add_exit("up","wizards/nalle/jerusalem/dav2h");
  short_desc = "Inside David's Tower, at the bottom of a staircase";
  long_desc =
"The only decoration in this room is an eastern carpet that has\n" +
"been placed on the floor and covers the area of the floor from\n" +
"the bedroom to the staircase, which is situated in the corner of\n" +
"the room. It seems you have almost reached the top of the tower, and\n" +
"you are quite eager indeed to find out who or what is kept upstairs.\n";
}

