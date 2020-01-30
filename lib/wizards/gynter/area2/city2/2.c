inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city2/1");
  add_exit("south","/wizards/gynter/area2/city2/9");
  /* setting desc */
  short_desc = "A dusty road";
  long_desc = "A dusty road leading into a village.\n"+
              "The road looks heavilly used, almost like\n"+
              "hundreds of people use it every day.\n";
}
