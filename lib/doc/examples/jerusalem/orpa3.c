inherit "room/room";

object monster,monster2;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/orphan");
    move_object(monster, this_object());
  }
if(!monster2) {
    monster2 = clone_object("/wizards/nalle/jerusalem/monsters/orphan");
    move_object(monster2, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/orpa2");
  add_exit("north","wizards/nalle/jerusalem/orpb3");
  short_desc = "A room full of desks";
  long_desc =
"You are in a room full of desks and chairs. A couple of  the\n" +
"of the orphans are sitting at the desks nibbling on some bread\n" +
"and slowly eating their soup. You hear the babbling of a teacher\n" +
"in the room to your north and notice the entrance to the orphanage\n" +
"in the room to your west.\n";
}

