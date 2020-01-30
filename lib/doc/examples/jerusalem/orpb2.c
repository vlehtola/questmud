inherit "room/room";

object monster,monster2;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/orphan");
    move_object(monster, this_object());
  }
if(!monster2) {
    monster2 = clone_object("/wizards/nalle/jerusalem/monsters/cook");
    move_object(monster2, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/orpb1");
  add_exit("east","wizards/nalle/jerusalem/orpb3");
  add_exit("south","wizards/nalle/jerusalem/orpa2");
  short_desc = "The kitchen";
  long_desc =
"This is where all the food seems to be made and served.\n" +
"There are large stoves and ovens in one corner and a large\n" +
"buffet-like table on which food is served in the middle of the\n" +
"room. There is a smell of cooked vedgetables constantly\n" +
"hovering around you.\n";
}

