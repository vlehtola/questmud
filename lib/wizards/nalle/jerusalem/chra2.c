inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/christianman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/chrb2");
  add_exit("south","wizards/nalle/jerusalem/vd2");
  add_exit("east","wizards/nalle/jerusalem/chra3");
  add_exit("west","wizards/nalle/jerusalem/chra1");
  short_desc = "Southern part of the Christian quarter";
  long_desc =
"This is the Southern part of the Christian quarter of Jerusalem.\n" +
"It is slightly less crowded here then on the main road, but still\n" +
"lots of people are scurrying in and out of the entrance to this\n" +
"quarter. The Via Dolorosa is to your south, and the other parts\n" +
"of the area inhabited by Christians are to your east, north and west.\n";
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

