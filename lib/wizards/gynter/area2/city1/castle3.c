inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/castle4");
  add_exit("west","/wizards/gynter/area2/city1/castle2");
  /* setting desc */
  short_desc = "A crude stone corridor";
  long_desc = "You are standing in a crude stone corridor.\n"+
              "The walls are crumbling due to lack of maintenance.\n"+
              "The corridor continues as far as you can see.\n";
}
