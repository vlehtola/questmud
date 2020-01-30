inherit "room/room";

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/house06");
  add_exit("south", "/wizards/ahma/orc/village/vil27");
  add_exit("east", "/wizards/ahma/orc/village/vil20");
  add_exit("southwest", "/wizards/ahma/orc/village/vil15");
  short_desc = "Intersection between Sralk and Zark streets";
  long_desc = "########### Sralk street continues to east and southwest. The Zark street\n" + 
              "#    H   |# begins its way to south. Village square can be seen in southeast,\n" + 
              "#   ,*---+# but it is surrounded by a deep moat. In north, sitting on the\n" + 
              "#  / | #### grass, is located a strange tent-like dwelling. It is made of\n" + 
              "########### wood and looks thoroughly very primitive.\n";
}

init() {
  ::init();
  add_action("map", "map");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}