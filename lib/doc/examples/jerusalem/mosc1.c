inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/mosman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/nalle/jerusalem/mosc2");
  add_exit("south","wizards/nalle/jerusalem/mosb1");
  short_desc = "Northwestern part of the Moslem quarter";
  long_desc =
"This is the northwestern part of the Moslem quarter of Jerusalem.\n" +
"This area seems slightly more quiet than the others, there are not\n" +
"many people here, just a few men spending time, sitting on the\n" +
"porches of their homes. You are occasionally startled by the sounds\n"+
"of a couple of chickens are running around in one corner.\n";
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
