inherit "room/room";

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/vil19");
  add_exit("south", "/wizards/ahma/orc/village/vil10");
  add_exit("west", "/wizards/ahma/orc/village/vil13");
  add_exit("east", "/wizards/ahma/orc/village/vil06");
  short_desc = "Intersection between Galor and Zark streets";
  long_desc = "########### The Galor street continues to west and east. The Zark street lies\n" + 
              "# H  | #### in north-south direction. The city square can be seen in northeast,\n" + 
              "#`+--*---+# but a deep moat is separating it from the road. The trees in the\n" + 
              "#    |   H# road banks are noticeably thinner and smaller in central than in the\n" + 
              "########### surrounding streets of this village.\n";
}

init() {
  ::init();
  add_action("map", "map");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}