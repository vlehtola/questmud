inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/salesman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/elattar2");
  add_exit("south","wizards/nalle/jerusalem/elattar3");
  add_exit("west","wizards/nalle/jerusalem/vd3");
  add_exit("east","wizards/nalle/jerusalem/vd4");
  short_desc = "The Central Square (Crossing of El Attar and Via Dolorosa)";
  long_desc =
"This is the crossing of the Via Dolorosa and the El Attar\n" +
"roads, also known as the central square. People are walking\n" +
"all around, in all directions, and salesmen are looking for\n" +
"gullible people that would be willing to buy their rubbish.\n" +
"In other words this place is crowded. \n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/csmap");
   return 1;
}
