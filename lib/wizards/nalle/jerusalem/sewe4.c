inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/sewsnake");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/sewe3");
  add_exit("south","wizards/nalle/jerusalem/sewe5");
  short_desc = "The sewers of Jerusalem";
  long_desc =
"You are in the sewers of Jerusalem, a massive complex built\n" +
"in order to get rid of sewage, and finally of the diseases\n" +
"that trouble this city relentlessly. The walls are made of rock\n" +
"and some material that reminds you of cement. Rats and snakes\n" +
"move around this area in large quantities. This part of the sewers\n" +
"is probably situated somewhere under the central part of Jerusalem.\n";

  set_water(3);
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

