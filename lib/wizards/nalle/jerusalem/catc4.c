inherit "room/room";
reset(arg) {

  add_exit("north","wizards/nalle/jerusalem/catd4");
  add_exit("west","wizards/nalle/jerusalem/catc3");
  add_exit("east","wizards/nalle/jerusalem/catc5");
  add_exit("south","wizards/nalle/jerusalem/catb4");
  short_desc = "In the main hall of the cathedral";
  long_desc =
"You are in the main hall of the cathedral, a corridor leads \n" +
"to the entrance, which is to your south. The hall continues\n" +
"north and there are rows of benches to your left and to your\n" +
"right.\n";
}

