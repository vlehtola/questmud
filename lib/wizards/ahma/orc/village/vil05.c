inherit "room/room";

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/vil08");
  add_exit("south", "/wizards/ahma/orc/village/vil03");
  add_exit("west", "/wizards/ahma/orc/village/vil06");
  add_exit("east", "/wizards/ahma/orc/village/vil07");
  short_desc = "Intersection between Galor and Ilem streets";
  long_desc = "########### The Galor street is leading to west and east and the Ilem street\n" + 
              "#### |  H # leads to north and south. In northwest you can see the town\n" + 
              "#+---*--+'# square, but a deep moat seems to be surrounding it. Some trees\n" + 
              "#H   |    # are growing in the roadside, but they are much thinner and smaller\n" + 
              "########### in the central part than in the surrounding streets of the village.\n";
}

init() {
  ::init();
  add_action("map", "map");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}
