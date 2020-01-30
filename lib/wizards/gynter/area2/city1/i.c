inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/d");
  add_exit("east","/wizards/gynter/area2/city1/j");
  add_exit("west","/wizards/gynter/area2/city1/h");
  /* setting desc */
  short_desc = "Falcon road";
  long_desc = "This is the road that binds the east and west side of the town\n"+
              "together. It is called Falcon road because of that it spreads it's wings\n"+
              "all over town. Strangely enough it is almost clean.\n";
}
