inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/castle2");
  add_exit("south","/wizards/gynter/area2/city1/castle8");
  add_exit("out","/wizards/gynter/area2/city1/4");
  /* setting desc */
  short_desc = "A crude stone corridor";
  long_desc = "You are standing in a crude stone corridor.\n"+
              "The corridor continues as far as you can see.\n";
}
