inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/monk");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/nalle/jerusalem/cata7");
  add_exit("west","wizards/nalle/jerusalem/catb6");
  add_exit("up","wizards/nalle/jerusalem/catbishop");
  add_exit("down","wizards/nalle/jerusalem/catcellar");
  short_desc = "A staircase";
  long_desc =
"You are in the western wing of the cathedral, at a staircase \n" +
"leading upstairs and downstairs. A smell of fermenting and\n" +
"fungae reaches your nose from downstairs. The way upstairs\n" +
"seems seldom used and is covered by a red carpet.\n";
}

