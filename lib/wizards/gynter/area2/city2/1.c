inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/workroom");
  add_exit("south","/wizards/gynter/area2/city2/2");
  /* setting desc */
  short_desc = "A dusty road";
  long_desc = "A dusty road leading into a village.\n"+
              "The road looks like if it has been used frequently for\n"+
              "several years.\n";
}
