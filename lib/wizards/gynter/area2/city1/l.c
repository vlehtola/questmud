inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/e");
  add_exit("south","/wizards/gynter/area2/city1/s");
  add_exit("east","/wizards/gynter/area2/city1/m");
  add_exit("west","/wizards/gynter/area2/city1/k");
  /* setting desc */
  short_desc = "The Head of the Falcon";
  long_desc = "This is the central point for the Falcon road.\n"+
              "The ground in this place is laid with marbles\n"+
              "so that it won't turn muddy if it rains.\n";
}
