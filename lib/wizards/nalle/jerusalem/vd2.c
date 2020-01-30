inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/salesman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/vd1");
  add_exit("east","wizards/nalle/jerusalem/vd3");
  add_exit("north","wizards/nalle/jerusalem/chra2");
  add_exit("south","wizards/nalle/jerusalem/armc2");
  short_desc = "Via Dolorosa (2nd block)";
  long_desc =
"This is the Via Dolorosa. You are at the entrances to the\n" +
"Christian (to the north) and the Armenian (to the south)\n" +
"quarters. Lots of different looking people are wandering\n" +
"along this road, especially members of the Christian \n" +
"and Armenian communities. \n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/vd2map");
   return 1;
}
