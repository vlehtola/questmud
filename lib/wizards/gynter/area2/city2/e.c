inherit "room/room";
reset(arg) {
  /* Assigning exits */
  add_exit("west","/wizards/gynter/area2/city2/d");
  add_exit("south","/wizards/gynter/area2/city2/k");
  /* setting desc */
  short_desc = "A main road";
  long_desc = "This is the main road of the village.\n"+
              "It is used by several people and is quite crowded by day.\n"+
              "But strangely there aren't so much as a scratch on the road.\n";
}
