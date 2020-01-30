inherit "room/room";

reset(arg) {
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/darke/city/garden/3g1");
  add_exit("northwest","/wizards/gynter/darke/city/garden/3g19");
  add_exit("west","/wizards/gynter/darke/city/Fcity2");
  /* setting desc */
  short_desc = "The entrance to the cactus Garden";
  long_desc = "This is the start of the garden of cactuss.\n"+
              "The more intuitive of the young darkelfs have\n"+
              "been tending to this garden.\n";
}
