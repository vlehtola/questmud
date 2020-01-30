inherit "room/room";
reset(arg) {
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/dav2a");
  add_exit("east","wizards/nalle/jerusalem/dav2c");
  short_desc = "Inside David's Tower";
  long_desc =
"You are inside David's Tower. The room you are in\n" +
"is expensively furnished. There is a table made of green\n" +
"marble in the middle of the room, and it is surrounded by\n" +
"comfortable looking couches and chairs. This must be the room\n" +
"where guests are entertained in. You may continue walking\n" +
"up towards higher parts of the tower, to the east, or back\n" +
"downwards to the north.\n";
}

