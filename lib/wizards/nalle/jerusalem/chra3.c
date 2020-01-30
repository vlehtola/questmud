inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/christianwoman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/chrb3");
  add_exit("west","wizards/nalle/jerusalem/chra2");
  short_desc = "Southeastern part of the Christian quarter";
  long_desc =
"This is the Southerneastern part of the Christian quarter of \n" +
"Jerusalem. This area is  obviously meant to be a residential \n" +
"area for the local habitants. The houses are in a fairly good \n" +
"condition, as are the thin cobblestoned roads that lead\n" +
"to the north and to the west.\n";
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

