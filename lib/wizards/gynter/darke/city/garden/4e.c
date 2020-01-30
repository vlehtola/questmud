inherit "room/room";

reset(arg) {
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/darke/city/garden/4g1");
  add_exit("northwest","/wizards/gynter/darke/city/garden/4g19");
   add_exit("east","/wizards/gynter/darke/city/Fcity2");
  /* setting desc */
  short_desc = "The entrance to the danderline Garden";
  long_desc = "This is the start of the garden of danderlines.\n"+
              "The more intuitive of the young darkelfs have\n"+
              "been tending to this garden.\n";
}
