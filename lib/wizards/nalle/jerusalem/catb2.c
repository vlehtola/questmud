inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/monk");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/nalle/jerusalem/cata2");
  add_exit("west","wizards/nalle/jerusalem/catb1");
  short_desc = "A room in the western wing";
  long_desc =
"You are in the western wing of the cathedral. There is a staircase \n" +
"leading upstairs and downstairs to your west. You hear the wind\n" +
"blowing from somewhere, possibly from the entry upstairs. There\n" +
"is a monk following your actions with his gaze here.\n";
}

