inherit "room/room";
int mob;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/vil21");
  add_exit("south", "/wizards/ahma/orc/village/vil20");
  short_desc = "Crossing-street between Nuft and Sralk streets";
  long_desc = "########### The crossing-road between Nuft and Sralk streets leads to north,\n" + 
              "#    |    # where the Nuft street is, and to south where lies the Sralk street.\n" + 
              "#    *    # There is lots of garbage tossed in both sides of this road, and the\n" + 
              "#H   |   H# stench which the garbage emits is really horrible. Few animals are\n" + 
              "########### digging the trash-piles to find something suitable for food.\n";

  if(mob < 1) { move_object(clone_object("/wizards/ahma/orc/mob/dog"), this_object()); mob++; }
}

init() {
  ::init();
  add_action("map", "map");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}

childdead() {
  mob--;
}