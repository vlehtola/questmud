inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/pilgrim");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/wgate");
  add_exit("east","wizards/nalle/jerusalem/vd2");
  short_desc = "Via Dolorosa (1st block)";
  long_desc =
"This is the Via Dolorosa. The western Jaffa gates are\n" +
"located to your west, and so you are in the western part\n" +
"of a town with a bustling economy, and a varied culture,\n" +
"called Jerusalem. This road continues far to your east\n" +
"and the road seems crowded all the way to its extremity. \n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/map");
   return 1;
}
