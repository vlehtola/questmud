inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/poorman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/vd8");
  add_exit("east","wizards/nalle/jerusalem/egate");
  short_desc = "Via Dolorosa (9th block)";
  long_desc =
"This is the Via Dolorosa. The eastern St. Stevens gate is\n" +
"located to your east, and so you are in the eastern part\n" +
"of town of Jerusalem. This road leads far to the west\n" +
"and you think you can see it crossing some other road\n" +
"somewhere in the central area of the town. A high tower\n"+ 
"looms quite close to you, to your northwest. \n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/vd9map");
   return 1;
}
