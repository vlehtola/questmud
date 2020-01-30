inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/area2/monsters/rat");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/nalle/area2/f3");
  add_exit("east","wizards/nalle/area2/d2");
  short_desc = "Avenue des Lepreux (1st block)";
  long_desc =
"This is the Avenue des Lepreux. The western wastelands\n" +
"are located to your west. To your east you see an entry \n" +
"into some building. The stench of the dead makes you\n" +
"you feel sick. Rats and lepers can be seen here.\n";
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

