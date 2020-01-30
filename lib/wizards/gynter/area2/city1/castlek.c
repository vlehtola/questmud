inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/castled");
  add_exit("west","/wizards/gynter/area2/city1/castlej");
  /* setting desc */
  short_desc = "The kings walk";
  long_desc = "This is the kings walk, it is rumored to be the only safe\n"+
              "haven left for the king. But now noone can be sure of anything.\n"+
              "Now the corridor is in such a depraved state that you can't seem\n"+
              "to figure out how the king can live in this castle.\n";
}
