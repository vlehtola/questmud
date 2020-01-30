inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/sewrat");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/sewg1");
  short_desc = "The sewers of Jerusalem";
  long_desc =
"You are in the sewers of Jerusalem, a massive complex built\n" +
"in an attempt to destroy diseases like the plague.\n" +
"Your surroundings are revolting. Peculiar looking slime and \n" +
"various types of fungi cover the humid rock walls. A very unpleasant\n" +
"odour has developped here in the course of time and this seems\n" +
"to be the ideal home for quite a number of rats and other similar\n" +
"rodents. A ladder leads up to some noisy place.\n";

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
  move_object(this_player(), "/wizards/nalle/jerusalem/mosb3.c");
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

