inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/area2/monsters/leper");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/area2/d1");
  add_exit("south","wizards/nalle/area2/necroshop");
  add_exit("east","wizards/nalle/area2/d3");
  short_desc = "Avenue des Lepreux (2nd block)";
  long_desc =
"This is the Avenue des Lepreux. There is a faint light\n" +
"shining from the entry to a building to your south. \n" +
"Lepers look at you suspiciously from their shadows.\n" +
"For some reason there are some slighly decomposed\n" +
"organs and piles of excrements by the entrance. \n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/area2/map");
   return 1;
}

