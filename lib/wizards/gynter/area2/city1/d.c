inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/8");
  add_exit("south","/wizards/gynter/area2/city1/i");
  /* setting desc */
  short_desc = "Entrance to the Rat Alley";
  long_desc = "This is one of the entrances to the most disgusting alley\n"+
              "in the world. There is garbage everywhere!\n";
}
