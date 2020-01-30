inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("east","/wizards/gynter/area2/city1/castleup3.c");
  add_exit("south","/wizards/gynter/area2/city1/castleup1.c");
  /* setting desc */
  short_desc = "A narrow corridor";
  long_desc = "This is the smallest, dirtiest, most unused corridor you\n"+
              "have ever seen. It is covered with dust, spiderwebs and\n"+
              "ratdroppings. It is just disgusting!\n";
}
