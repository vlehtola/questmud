inherit "room/room";

object monster,monster2;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/area2/monsters/bandit");
    move_object(monster, this_object());
  }
 if(!monster2) {
    monster2 = clone_object("/wizards/nalle/area2/monsters/bandit2");
    move_object(monster2, this_object());
 }
  if(arg) return;
  add_exit("north","wizards/nalle/area2/d3");
  add_exit("south","wizards/nalle/area2/c3");
  short_desc = "A thin passage";
  long_desc =
"You are on a thin passage linking the Avenue des\n" +
"Lepreux  to the Avenue des Nocturnes. There are no\n" +
"lights here and the atmosphere feels quite hostile\n" +
"despite the apparent silence.\n";
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

