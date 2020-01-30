inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/area2/monsters/rat");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/area2/d2");
  add_exit("south","wizards/nalle/area2/nocjalep");
  add_exit("east","wizards/nalle/area2/d4");
  short_desc = "Avenue des Lepreux (3rd block)";
  long_desc =
"This is the Avenue des Lepreux. There is a thin\n" +
"passage leading south to the Avenue des Nocturnes. \n" +
"Lepers look at you suspiciously from their shadows,\n" +
"and rats squirm in the corners. The panting of the\n" +
"dying makes you feel nervous. \n";
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

