inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("south","/wizards/gynter/area2/city2/s");
  /* setting desc */
  short_desc = "Approach to the holy center";
  long_desc = "The road continues closer to the Control Tower.\n"+
              "In the far a dark room can be seen but it is still far away.\n";
}
