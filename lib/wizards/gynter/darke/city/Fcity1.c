inherit "room/room";

reset(arg) {
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/darke/city/Rcity1");
  add_exit("south","/wizards/gynter/darke/city/Fcity2");
   add_exit("east","/wizards/gynter/darke/city/garden/1e");
  add_exit("west","/wizards/gynter/darke/city/garden/2e");
  /* setting desc */
  short_desc = "The Fairy walk";
  long_desc = "This is one of the most beautiful places you\n"+
              "have ever seen. The walk is lined with roses.\n"+
              "You can hardly belive that a race like the darkelfs\n"+
              "could create something this beautiful.\n";
}
