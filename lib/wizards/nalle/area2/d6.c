inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/area2/monsters/rat");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/area2/d5");
  add_exit("east","wizards/nalle/area2/d7");
  short_desc = "Avenue des Lepreux (6th block)";
  long_desc =
"This is the Avenue des Lepreux. The eastern wastelands\n" +
"are located quite a bit to your east. An entry to the \n" +
"monastery is further to your west. The stench of the\n" +
"is apparent here. Rats and lepers inhabit this street.\n";
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

