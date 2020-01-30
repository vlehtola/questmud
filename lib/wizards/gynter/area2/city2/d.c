inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city2/e");
  add_exit("west","/wizards/gynter/area2/city2/c");
  /* setting desc */
  short_desc = "A main road";
  long_desc = "This is the main road of the village.\n"+
              "The road is clean and shiny. It is made of some strange material,\n"+
              "it is white and sparkles like it's made of crystal.\n";
}
