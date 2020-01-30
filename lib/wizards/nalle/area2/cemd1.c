inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/area2/monsters/skeleton");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/nalle/area2/b3");
  add_exit("east","wizards/nalle/area2/cemc1");
  add_exit("west","wizards/nalle/area2/ceme1");
  add_exit("north","wizards/nalle/area2/cemd2");
  short_desc = "The entry to the cemetary";
  long_desc =
"This is the entry to the graveyard. It seems \n" +
"unnaturally large for a fairly small town like this\n" +
"one. You see some movement further in the graveyard.\n" +
"The plants here are long dead, and decomposing due to\n" +
"bad caretaking.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/area2/cemmap");
   return 1;
}
