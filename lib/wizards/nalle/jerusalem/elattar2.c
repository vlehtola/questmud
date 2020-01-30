inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/pilgrim");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/elattar1");
  add_exit("south","wizards/nalle/jerusalem/cs");
  short_desc = "El Attar (2nd block)";
  long_desc =
"This is the 2nd block of the El Attar road, just north from\n" +
"the central square. You see honest looking people scurrying\n" +
"all around, in all directions, mostly into the chriastian and the\n" +
"quarters. \n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/elattar2map");
   return 1;
}
