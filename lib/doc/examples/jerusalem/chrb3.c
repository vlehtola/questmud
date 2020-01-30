inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/salesman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/chrc3");
  add_exit("west","wizards/nalle/jerusalem/chrb2");
  add_exit("south","wizards/nalle/jerusalem/chra3");
  short_desc = "Eastern part of the Christian quarter";
  long_desc =
"This is the eastern part of the Christian quarter of the city of\n" +
"Jerusalem. There are lots of shops and salesmen in this area. The \n" +
"citizens are walking around peacefully and looking at what the\n" +
"merchants have to offer. The roads here go to the north, the south\n" +
"and to the west.\n";
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

