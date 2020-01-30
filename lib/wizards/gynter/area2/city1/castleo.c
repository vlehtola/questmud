inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/castlef");
  add_exit("west","/wizards/gynter/area2/city1/castlen");
  /* setting desc */
  short_desc = "A crude stone corridor";
  long_desc = "You are standing in a crude stone corridor.\n"+
              "The masonry that keeps the stone in the wall\n"+
              "and ceiling is about to become dust. It will\n"+
              "not take a long time before these walls will fall.\n";
}
