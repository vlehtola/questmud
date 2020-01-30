inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/monk");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/nalle/jerusalem/cata6");
  add_exit("east","wizards/nalle/jerusalem/catb7");
  short_desc = "A room in the eastern wing";
  long_desc =
"You are in the eastern wing of the cathedral. There is a staircase \n" +
"leading upstairs and downstairs to your east. You hear some faint\n" +
"from the entry downstairs. A smell of fermenting penetrates you\n" +
"nostrils also originating from downstairs.\n";
}

