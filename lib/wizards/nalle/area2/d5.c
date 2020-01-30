inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/area2/monsters/leper");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/area2/a5");
  add_exit("south","wizards/nalle/area2/monastery");
  add_exit("east","wizards/nalle/area2/d6");
  short_desc = "Avenue des Lepreux (5th block)";
  long_desc =
"This is the Avenue des Lepreux. The monastery of Vallis\n" +
"Mortis is located to your south. The northern end of the \n" +
"Bourbon Avenue is to your west. This part of the town\n" +
"seems to be inhabited mostly by lepers and rats. They\n" +
"observe your movements suspiciously.\n";
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

