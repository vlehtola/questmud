inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/sewrat");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/nalle/jerusalem/sewc2");
  short_desc = "In the sewers of Jerusalem";
  long_desc =
"You are in the sewers of Jerusalem, a massive complex built\n" +
"in order to get rid of sewage, and finally of the diseases\n" +
"that trouble this city relentlessly. The walls are made of rock\n" +
"and some material that reminds you of cement. Rats and snakes\n" +
"move around this area in large quantities. This part of the sewers\n" +
"smells slightly of wine, which is quite surprising. A moss covered\n" +
"ladder leads up to somewhere, where something seems to emit light.\n";

  set_water(3);
}

init() {
    ::init();
   add_action("map", "map");
   add_action("climb", "climb");
}

climb(str) {
  if(str == "ladder") {
  say(this_player()->query_name()+" climbs up the ladder and leaves the sewers.\n");
  write("You climb up the ladder and find yourself in a big barrel. You promptly remove its lid an climb out of it entering a torch lit room.\n");
  move_object(this_player(), "/wizards/nalle/jerusalem/catcellar3e.c");
  return 1;
  }
    return 1;
}

map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/sewmap");
   return 1;
}

