inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/salesman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/vd4");
  add_exit("east","wizards/nalle/jerusalem/vd6");
  add_exit("north","wizards/nalle/jerusalem/mosa2");
  add_exit("south","wizards/nalle/jerusalem/jewc2");
  short_desc = "Via Dolorosa (5th block)";
  long_desc =
"This is the fifth block of the Via Dolorosa, at the entries to\n" +
"to the Moslem and the Jewish quarters. The heat and the humidity\n" +
"combined with the awful smells hovering in this area make you\n" +
"feel sick. You would very much like to go somewhere a bit more\n" +
"quiet.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/vd5map");
   return 1;
}
