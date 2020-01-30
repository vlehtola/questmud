inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/davguard2");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/dav2d");
  add_exit("west","wizards/nalle/jerusalem/dav2b");
  short_desc = " Inside David's Tower";
  long_desc =
"You have entered a passageway, well decorated, \n" +
"like the rest of the tower, but the room itself does\n" +
"seem to have a distinct function in itself, except\n" +
"perhaps a guarding point.\n";
}

