inherit "room/room";

reset(arg) {

  add_exit("north","wizards/nalle/jerusalem/cate4");
  add_exit("west","wizards/nalle/jerusalem/catd3");
  add_exit("east","wizards/nalle/jerusalem/catd5");
  add_exit("south","wizards/nalle/jerusalem/catc4");
  short_desc = "In the main hall of the cathedral";
  long_desc =
"You are in the middle of main hall of the cathedral. You notice\n" +
"monks sitting on the benches to your left and to your right.\n" +
"You take a moment to admire the structure of the church. The\n" +
"craftmanship on the roof and the multicoloured windows is admirable.\n";
}

