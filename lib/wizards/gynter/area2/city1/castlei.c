inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/castlej");
  add_exit("west","/wizards/gynter/area2/city1/castleh");
  /* setting desc */
  short_desc = "The kings walk";
  long_desc = "This is supposed to be the safest place in the kingdom\n"+
              "nut now noone can be sure of anything. Now the corridor\n"+
              "is in such a depraved state that you can't seem to figure\n"+
              "out how the king can live in this castle.\n";
}
