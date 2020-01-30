inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/sewrat");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/nalle/jerusalem/sewf1");
  add_exit("south","wizards/nalle/jerusalem/sewe2");
  short_desc = "The sewers under the El Attar street";
  long_desc =
"This is the 'Cloaca Maxima', a sewage system built by\n" +
"the Duranghomians in an attempt to destroy diseases like the plague.\n" +
"Your surroundings are revolting. Peculiar looking slime and \n" +
"various types of fungi cover the humid rock walls. A very unpleasant\n" +
"odour has developped here in the course of time and this seems\n" +
"to be the ideal home for quite a number of rats and other similar\n" +
"rodents. You think you must be somewhere under the El Attar street.\n" +
"A grime covered ladder leads up to an exit from the sewers. \n";

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
  write("You carefully climb up the ladder and find yourself outside.\n");
  move_object(this_player(), "/wizards/nalle/jerusalem/elattar1.c");
  say(this_player()->query_name()+" arrives from the sewers, opening a small lid and closing it behind him.\n");
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

