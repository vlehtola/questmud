inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/moswoman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/mosb2");
  add_exit("south","wizards/nalle/jerusalem/vd5");
  add_exit("east","wizards/nalle/jerusalem/mosa3");
  add_exit("west","wizards/nalle/jerusalem/mosa1");
  short_desc = "Southern part of the Moslem quarter";
  long_desc =
"This is the Southern part of the Moslem quarter of Jerusalem.\n" +
"The smell of freshly baked bread hovers around your nostrils,\n" +
"originating from small stands placed here and there, where cloaked\n" +
"women are selling foods. The Via Dolorosa is to your south, and \n" +
"the other parts of the Moslem quarter lie to your west, north and east.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/mmap");
   return 1;
}
