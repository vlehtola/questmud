inherit "room/room";
int mob;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/house03");
  add_exit("west", "/wizards/ahma/orc/village/vil03");
  short_desc = "Eastern part of Orgam street";
  long_desc = "########### The Orgam street ends in here. A crubby-looking shack is located\n" + 
              "#|   H    # in north. The doorway gapes without doors, so the shack can be\n" + 
              "#+---*    # entered from here. Where the road ends, starts a thick forest.\n" + 
              "#         # Seems that no more trees were cut down than it was needed when\n" + 
              "########### this small village was built. The road is lined with green bushes in\n" +
              "            south.\n";

  if(mob < 2) { move_object(clone_object("/wizards/ahma/orc/mob/dog"), this_object()); mob++; }
  if(mob < 2) { move_object(clone_object("/wizards/ahma/orc/mob/dog"), this_object()); mob++; }
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
