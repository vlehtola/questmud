inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/castleb");
  add_exit("west","/wizards/gynter/area2/city1/castle0");
  /* setting desc */
  short_desc = "The kings walk";
  long_desc = "This is the kings walk.\n"+
              "Now the corridor is in such a depraved state\n"+
              "that you can't seem to figure out how the king\n"+
              "can live in this castle.\n";
}
