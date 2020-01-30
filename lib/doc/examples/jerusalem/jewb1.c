inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/jewwoman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/jewc1");
  add_exit("east","wizards/nalle/jerusalem/jewb2");
  add_exit("south","wizards/nalle/jerusalem/jewa1");
  add_exit("enter","wizards/nalle/jerusalem/tenta1");
  short_desc = "Western part of the Jewish Quarter";
  long_desc =
"The western part of the Jewish quarter is full of large\n" +
"rectangular houses made of chalkstone. The houses seem\n" +
"at least externally clean, and the people here seem happy.\n" +
"A small tent catches your eye here.\n";
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

