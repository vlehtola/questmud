inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/element/air/14");
  add_exit("west","/wizards/gynter/element/air/12");
  /* setting desc */
  short_desc = "Emptyness";
  long_desc = "There is nothing around you at all. There is no floor, ceiling,\n"+
              "or walls. Just a vast emptyness. Infact the only thing you can\n"+
              "see that signals that this is a room is the doorframes of the\n"+
              "doors that lead out of here.\n";
  set_not_out(3);
  set_light(1);
}
