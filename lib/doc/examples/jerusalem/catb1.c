inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/monk");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/nalle/jerusalem/cata1");
  add_exit("east","wizards/nalle/jerusalem/catb2");
  add_exit("up","wizards/nalle/jerusalem/cattower");
  add_exit("down","wizards/nalle/jerusalem/catdungeon");
  short_desc = "A staircase";
  long_desc =
"You are in the eastern wing of the cathedral, at a staircase \n" +
"leading upstairs and downstairs. A cold breeze flows in from\n" +
"upstairs and makes you feel a bit chilly. Otherwise it is quite\n" +
"calm and quiet here.\n";
}

