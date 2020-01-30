inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/sewrat");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("north","wizards/nalle/jerusalem/sewe4");
  add_exit("south","wizards/nalle/jerusalem/sewe6");
  short_desc = "The sewers of Jerusalem";
  long_desc =
"The sewers here smell awful. The bitter odours of urine and\n" +
"vomit cannot be overlooked in this part of the sewer complex.\n" +
"This probably means you are getting closer to the poor \n" + 
"neighbourhood of Jerusalem. Rats and snakes are everywhere to be\n" +
"seen, above the surface of the sewage. You can only imagine what\n" +
"might reside at bottom of these underground rivers of excrements,\n" +
"waste, and decayed organisms. This part of the sewers\n" +
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

