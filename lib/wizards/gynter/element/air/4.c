inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("northwest","/wizards/gynter/element/air/2");
  add_exit("southeast","/wizards/gynter/element/air/7");
  /* setting desc */
  short_desc = "Emptyness";
  long_desc = "Doorframes. Four doorframes and nothing more.\n"+
              "The floor is transparent, the roof is transparent and\n"+
              "the walls are transparent. Only thing that is visible\n"+
              "is the doorframes.\n";
  set_not_out(3);
  set_light(1);
}
