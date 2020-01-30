inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/pilgrim");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/cs");
  add_exit("east","wizards/nalle/jerusalem/vd5");
  short_desc = "Via Dolorosa (4th block)";
  long_desc =
"This is the fourth block of the Via Dolorosa, one block east\n" +
"from the central square. The entrance to the Moslem quarter\n" +
"is to your east. There are quite a bit of people here and because\n" +
"of the heat, the bodily odours of the citizens are most apparent.\n" +
"The entrance to the Jewish quarter of Jerusalem is to your east too.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/vd4map");
   return 1;
}
