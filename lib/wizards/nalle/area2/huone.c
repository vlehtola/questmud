inherit "room/room";

object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/nalle/area2/monsters/leper");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/area2/c5");
  add_exit("south","wizards/nalle/area2/f6");
  short_desc = "Avenue des Nocturnes (6th block)";
  long_desc =
"This is the Avenue des Nocturnes. The eastern wastelands\n" +
"are located to your east. This is the eastern extremity of\n" +
"avenue. It is very dark here, and this part of the\n" +
"town seems even more quiet then the others.\n";
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

