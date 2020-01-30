inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/moswoman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/nalle/jerusalem/mosc3");
  add_exit("south","wizards/nalle/jerusalem/mosb2");
  add_exit("west","wizards/nalle/jerusalem/mosc1");
  short_desc = "Northern part of the Moslem quarter";
  long_desc =
"This is the Northern part of the Moslem quarter of Jerusalem.\n" +
"This part of the town is mostly occupied by small shops and\n" +
"commerces. You see women walking with their children, in search\n" +
"for the cheapest places to buy food from. There are also a few\n"+
"salesmen walking around.\n";
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
