inherit "room/room";

reset(arg) {
  /* Assigning exits */
  add_exit("north","/wizards/gynter/area2/city1/s");
  add_exit("south","/wizards/gynter/area2/city1/w");
  /* setting desc */
  short_desc = "The Golden Walk";
  long_desc = "Once this road was covered with gold, the houses covered with\n"+
              "gold. But now the only thing the road and houses are covered with\n"+
              "is grey dust and brown mud.\n";
}
