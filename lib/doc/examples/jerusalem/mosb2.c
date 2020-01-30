inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/pilgrim");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/mosc2");
  add_exit("east","wizards/nalle/jerusalem/mosb3");
  add_exit("south","wizards/nalle/jerusalem/mosa2");
  add_exit("west","wizards/nalle/jerusalem/mosb1");
  short_desc = "Central part of the Moslem quarter";
  long_desc =
"This is the central part of the Moslem quarter of Jerusalem.\n" +
"There are many people here and you manage to notice some shops\n" +
"and private residences here and there, but this place seems to\n" +
"mainly be used as the local marketplace, and that causes the\n"+
"constant presence of people and animals.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/mmap");
   return 1;
}
