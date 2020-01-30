inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/christianman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/chrc2");
  add_exit("south","wizards/nalle/jerusalem/chrb3");
  short_desc = "The Northeastern of the Christian quarter";
  long_desc =
"This is the northeastern part of the Christian quarter of the city of\n" +
"Jerusalem. There is a small cathedral to your southwest, and the \n" +
"part of town you are in is not very densely populated, it seems.\n" +
"The houses are in a worse state than a few blocks south and the\n" +
"people here seem poorer.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/cmap");
   return 1;
}

