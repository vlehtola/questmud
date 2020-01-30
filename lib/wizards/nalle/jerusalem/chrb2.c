inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/christianwoman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/chrc2");
  add_exit("west","wizards/nalle/jerusalem/chrb1");
  add_exit("south","wizards/nalle/jerusalem/chra2");
  add_exit("east","wizards/nalle/jerusalem/chrb3");
  add_exit("enter","wizards/nalle/jerusalem/chrcat");
  short_desc = "The center of the Christian quarter";
  long_desc =
"This is the central part of the Christian quarter of the city of\n" +
"Jerusalem. The Church of the Holy Sepulchre is located here, for those\n" +
"who practise the Christian religion, it is open for others too however.\n" +
"This part of the town does not seems as crowded as the others,\n" +
"thanks to the smaller density of residences.\n";
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

