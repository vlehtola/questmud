inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/pilgrim");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/nalle/jerusalem/chrc2");
  add_exit("south","wizards/nalle/jerusalem/chrb1");
  add_exit("enter","wizards/nalle/jerusalem/chrc1enter");
  short_desc = "The Northwestern part of the Christian quarter";
  long_desc =
"This is the northwestern part of the Christian quarter of the city of\n" +
"Jerusalem. There is a small cathedral to your southeast, and the \n" +
"part of the town you are now in seems to be occupied by a smallish.\n" +
"funeral area. There are thin cobblestoned roads leading to the east and\n" +
"to the south.\n";
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

