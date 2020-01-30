inherit "room/room";

reset(arg) {
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/darke/city/Fcity1");
  add_exit("east","/wizards/gynter/darke/city/garden/3e");
  add_exit("west","/wizards/gynter/darke/city/garden/4e");
  /* setting desc */
  short_desc = "The Fairy walk";
  long_desc = "The end of the Fairy walk. But this room is, if possible,\n"+
              "even more beautiful than the room before.\n";
}
