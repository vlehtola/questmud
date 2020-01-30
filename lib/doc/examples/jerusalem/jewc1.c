inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/pilgrim");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/nalle/jerusalem/jewc2");
  add_exit("south","wizards/nalle/jerusalem/jewb1");
  short_desc = "Northwestern part of the Jewish Quarter";
  long_desc =
"The Northwestern part of the Jewish quarter is one of the finest\n" +
"residential areas in Jerusalem. Trees and bushes decorate\n" +
"the paved walkways, and the people here are dressed neatly\n" +
"and accordingly with the current trends.\n";
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

