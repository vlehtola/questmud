inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/christianwoman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/chrb1");
  add_exit("east","wizards/nalle/jerusalem/chra2");
  short_desc = "Southwestern part of the Christian quarter";
  long_desc =
"This is the Southernwestern part of the Christian quarter of \n" +
"Jerusalem. There are many large houses in this area, meant \n" +
"for the local habitants. They are in a fairly good shape and the\n" +
"people here are seemingly happy. Thin cobblestoned roads lead\n" +
"to the north and to the east.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/cmap");
   return 1;
}

