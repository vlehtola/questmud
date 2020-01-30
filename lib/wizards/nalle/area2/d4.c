inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/area2/monsters/rat");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/area2/d3");
  add_exit("east","wizards/nalle/area2/a5");
  short_desc = "Avenue des Lepreux (4th block)";
  long_desc =
"This is the Avenue des Lepreux. The Bourbon Avenue\n" +
"is located to your east. This is the filthiest part of the\n" +
"town. Lepers walk these rat infested streets in great\n" +
"numbers.\n";
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

