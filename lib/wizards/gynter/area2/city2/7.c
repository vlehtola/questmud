inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city2/8");
  add_exit("west","/wizards/gynter/area2/city2/6");
  /* setting desc */
  short_desc = "A main road";
  long_desc = "This is the main road of the village.\n"+
              "It is used by several people and\n"+
              "is quite crowded by day.\n";
}
