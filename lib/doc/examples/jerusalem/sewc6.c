inherit "room/room";

object monster,monster2;

reset(arg) {

  if(arg) return; /* added by Celtron */

  monster = clone_object("/wizards/nalle/jerusalem/monsters/judean");
  move_object(monster, this_object());
  monster2 = clone_object("/wizards/nalle/jerusalem/monsters/brian");
  move_object(monster2, this_object());
  add_exit("east","wizards/nalle/jerusalem/sewd6");
  short_desc = "The sewers of Jerusalem";
  long_desc =
"This place you are in is a bit cleaner than the others in the\n" +
"sewers. There is a desk in the middle of the room, a small closet\n" +
"in the corner and two men sitting around the table, the other one\n" +
"has cover his face with black cloths, and the other one with white\n" +
"ones.\n";

  set_water(1);
}

init() {
    ::init();
   add_action("map", "map");
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/sewmap");
   return 1;
}
