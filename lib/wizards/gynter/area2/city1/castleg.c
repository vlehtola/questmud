inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/castleh");
  add_exit("west","/wizards/gynter/area2/city1/castlef");
  /* setting desc */
  short_desc = "The kings walk";
  long_desc = "This is the kings walk, it is rumored to be the only safe\n"+
              "haven left for the king. Now the corridor is in such a\n"+
              "depraved state that you can't seem to figure out how\n"+
              "the king can live in this castle.\n";
}
