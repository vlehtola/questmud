inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("south","/wizards/gynter/area2/city2/u");
  /* setting desc */
  short_desc = "Approach to the holy center";
  long_desc = "This is the road that connect to one of the control towers.\n"+
              "The road seems to be built out of diamonds!\n";
}
