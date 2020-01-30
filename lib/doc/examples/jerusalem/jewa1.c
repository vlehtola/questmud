inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/salesman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/jewb1");
  add_exit("east","wizards/nalle/jerusalem/jewa2");
  short_desc = "Southwestern part of the Jewish Quarter";
  long_desc =
"The southwestern part of the Jewish quarter is quite peaceful.\n" +
"The density of residences is quite small, but they seem quite\n" +
"expensive. People seem to come here to see the southern\n" +
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

