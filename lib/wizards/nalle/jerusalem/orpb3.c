inherit "room/room";

object monster,monster2;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/orphan");
    move_object(monster, this_object());
  }
if(!monster2) {
    monster2 = clone_object("/wizards/nalle/jerusalem/monsters/teacher");
    move_object(monster2, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/orpb2");
  add_exit("south","wizards/nalle/jerusalem/orpa3");
  short_desc = "The classroom";
  long_desc =
"This part of the orphanage seems to be used for teaching\n" +
"and there is therefore a teacher sitting in a chair infront of\n" +
"a couple of his pupils. The only items the teacher seems to\n" +
"need for teaching is his chair and his cane, such things as\n" +
"a blackboard and chalk seem to be unnecessary.\n";
}

