inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/castle8");
  add_exit("south","/wizards/gynter/area2/city1/castlel");
  /* setting desc */
  short_desc = "A crude stone corridor";
  long_desc = "You are standing in a crude stone corridor.\n"+
              "The masonry that keeps the stone in the wall and ceiling\n"+
              "is about to become dust. The corridor continues as far as\n"+
              "you can see.\n";
}
