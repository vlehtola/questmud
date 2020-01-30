inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/mosman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/mosb3");
  add_exit("west","wizards/nalle/jerusalem/mosa2");
  short_desc = "Southeastern part of the Moslem quarter";
  long_desc =
"This is the southeastern part of the Moslem quarter of Jerusalem.\n" +
"The houses here are not in a very good shape and because of the\n" +
"high density of the residences people have to live in houses with\n" +
"quite a few floors. All the entries to the houses have an arched shape\n"+
"as do all the windows.\n";
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
