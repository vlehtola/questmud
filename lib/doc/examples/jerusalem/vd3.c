inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/pilgrim");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/vd2");
  add_exit("east","wizards/nalle/jerusalem/cs");
  short_desc = "Via Dolorosa (3rd block)";
  long_desc =
"This is the Via Dolorosa. The entrances to the Christian\n" +
"and the Armenian quarters are to your west and the central-\n" +
"square, the crossing of the Via Dolorosa and El Ataar, is\n" +
"to your west. It seems to be very crowded and full of merchants\n" +
", salesmen, pilgrims and even cattle. \n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/vd3map");
   return 1;
}




