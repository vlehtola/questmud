inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("northeast","/wizards/gynter/element/air/1");
  add_exit("southwest","/wizards/gynter/element/air/5");
  /* setting desc */
  short_desc = "Emptyness";
  long_desc = "There is nothing around you at all. There is no floor, ceiling\n"+
              "or walls. Just a vast emptyness. The only thing you can\n"+
              "see that reminds you of a normal room is the doorframes.\n";
  set_not_out(3);
  set_light(1);
}
