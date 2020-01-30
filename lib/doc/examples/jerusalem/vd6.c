inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/salesman");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/vd5");
  add_exit("east","wizards/nalle/jerusalem/vd7");
  short_desc = "Via Dolorosa (6th block)";
  long_desc =
"This is the sixth block of the Via Dolorosa, the entries to\n" +
"to the Moslem and the Jewish quarters are to your west. A white\n" +
"tower, made of chalkstone looms further in the northeastern corner\n" +
"of the city. There are slightly less people here then in the other\n" +
"parts of the town, since the habitation is not as dense here as in\n"+
"the western part of the city.\n";
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/vd6map");
   return 1;
}
