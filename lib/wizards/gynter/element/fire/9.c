inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("west","/wizards/gynter/element/fire/8");
  add_exit("east","/wizards/gynter/element/fire/10");
  /* setting desc */
  short_desc = "A small corridor";
  long_desc = "You are standing in a small corridor.\n"+
              "There is almost no room to walk without touching\n"+
              "the flames in the walls.\n";
}
