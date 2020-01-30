inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/salesman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/jewb2");
  add_exit("east","wizards/nalle/jerusalem/jewa3");
  add_exit("west","wizards/nalle/jerusalem/jewa1");
  short_desc = "Southern part of the Jewish Quarter";
  long_desc =
"The southern part of the Jewish quarter is quite quiet.\n" +
"There are only a few small houses here, and the only reason\n" +
"for which people seem to come here for is to see the great\n" +
"rock wall, which is of great religious significance to them.\n";
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

