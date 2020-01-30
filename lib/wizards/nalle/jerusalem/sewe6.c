inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/sewrat");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/sewe5");
  add_exit("west","wizards/nalle/jerusalem/sewd6");
  short_desc = "The sewers of Jerusalem";
  long_desc =
"The sewers here smell awful. The bitter odours of urine and\n" +
"vomit cannot be overlooked in this part of the sewer complex.\n" +
"This probably means you are getting closer to the poor \n" + 
"neighbourhood of Jerusalem. Rats and snakes are everywhere to be\n" +
"seen, above the surface of the sewage. You can only imagine what\n" +
"might reside at bottom of these underground rivers of excrements,\n" +
"waste, and decayed organisms. A heavily oxidized iron ladder\n" +
"leads up to a southern part of Jerusalem.\n";

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
  move_object(this_player(), "/wizards/nalle/jerusalem/elattar4.c");
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

