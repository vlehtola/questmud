inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/castle6");
  add_exit("south","/wizards/gynter/area2/city1/castleb");
  /* setting desc */
  short_desc = "The kings walk";
  long_desc = "This is the kings walk, it is rumored to be the only safe\n"+
              "haven left in the kingdom. On the walls there used to hang\n"+
              "large tapestries and you can still see where they once hung.\n"+
              "But because of the war those had to be sold. Now the corridor\n"+
              "is in such a depraved state that you can't seem to figure\n"+
              "out how the king can live in this castle.\n";
}
