inherit "room/room";
int mob;

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/village/vil23");
  add_exit("northwest", "/wizards/ahma/orc/village/vil25");
  short_desc = "Eastern part of Nuft street";
  long_desc = "########### The Nuft street continues to south and northwest. A bigger hut can\n" + 
             "#  \\      # be seen over a small distance in north. From eastern side the road\n" + 
              "#   `*    # is lined with some thick bushes and trees. Some animals can be\n" + 
              "#    |    # seen moving in the forest behind the bushes, but the forest cannot\n" + 
              "########### be entered from here due to the thick population of plants.\n";

  if(mob < 1) { move_object(clone_object("/wizards/ahma/orc/mob/walker02"), this_object()); mob++; }
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