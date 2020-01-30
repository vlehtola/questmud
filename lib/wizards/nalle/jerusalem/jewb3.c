inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/jewwoman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/jewc3");
  add_exit("west","wizards/nalle/jerusalem/jewb2");
  add_exit("south","wizards/nalle/jerusalem/jewa3");
  short_desc = "Eastern part of the Jewish Quarter";
  long_desc =
"The eastern part of the Jewish quarter is full of little\n" +
"shops and boutiques. You also notice some residences\n" +
"and cafes on higher floors of the buildings here. There\n" +
"are a bit more people here than in the other parts of this quarter.\n";
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

