inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/area2/monsters/leper");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/area2/d6");
  add_exit("south","wizards/nalle/area2/f6");
  short_desc = "Avenue des Lepreux (7th block)";
  long_desc =
"This is the Avenue des Lepreux. The eastern wastelands\n" +
"are located to your south. This is the eastern extremity of\n" +
"the avenue. It is very dark here, and for some reason there\n" +
"are numerous lepers and other sick people gathered here.\n" +
"You notice that some of them lay dead on the pavement.\n";
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
