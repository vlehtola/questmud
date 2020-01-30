inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/jewman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/vd5");
  add_exit("south","wizards/nalle/jerusalem/jewb2");
  add_exit("west","wizards/nalle/jerusalem/jewc1");
  add_exit("east","wizards/nalle/jerusalem/jewc3");
  short_desc = "Northern part of the Jewish Quarter";
  long_desc =
"You are in the northern part of the Jewish quarter of Jerusalem.\n" +
"There are quite a bit of people here, mostly salesmen and\n" +
"fairly wealthy looking people looking for things to buy. The houses\n" +
"here are almost all white and are in a good shape.\n";
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

