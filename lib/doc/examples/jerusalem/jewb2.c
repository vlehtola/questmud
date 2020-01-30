inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/jewman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/jewc2");
  add_exit("west","wizards/nalle/jerusalem/jewb1");
  add_exit("east","wizards/nalle/jerusalem/jewb3");
  add_exit("south","wizards/nalle/jerusalem/jewa2");
  short_desc = "Central part of the Jewish Quarter";
  long_desc =
"The central part of the Jewish quarter is mostly dedicated\n" +
"to a large marketplace, filled with people trying to sell\n" +
"lots of different kinds of things, from foods to clothes.\n" +
"The area is clean and there are not too many people here.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/jmap");
   return 1;
}

