inherit "room/room";
int mob;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/vil28");
  add_exit("south", "/wizards/ahma/orc/village/vil05");
  short_desc = "Central part of Ilem street";
  long_desc = "########### The Ilem street continues to north and south. In west can be seen\n" + 
              "#### |    # the town square, but a deep moat is separating it from the road.\n" + 
              "#### *    # Behind a short distance to east you can see an entrance leading\n" + 
              "#### |  H # deeper into the forest which is surrounding this village. Some\n" + 
              "########### conspicuously shiny object is lying in the bank of the road.\n";

  items = allocate(4);
  items[0] = "shiny object";
  items[1] = "As you curiously take a closer look at the shining object you become sure\n" + 
             "that the object is a mithril coin. But the bad thing is that the coin has\n" + 
             "been stuck into a pile of some creature's crap. You do not want to put your\n" + 
             "life in danger by touching the crap, nor the crappy coin";
  items[2] = "object";
  items[3] = "As you curiously take a closer look at the shining object you become sure\n" + 
             "that the object is a mithril coin. But the bad thing is that the coin has\n" + 
             "been stuck into a pile of some creature's crap. You do not want to put your\n" + 
             "life in danger by touching the crap, nor the crappy coin";

  if(mob < 1) { move_object(clone_object("/wizards/ahma/orc/mob/man"), this_object()); mob++; }
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
