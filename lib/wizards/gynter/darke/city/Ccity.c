inherit "room/room";

reset(arg) {
  if(arg) return;
  /* Assigning exits */
  add_exit("north","/wizards/gynter/darke/city/Wcity4");
  add_exit("south","/wizards/gynter/darke/city/Orcity1");
  add_exit("east","/wizards/gynter/darke/city/Rcity5");
  add_exit("west","/wizards/gynter/darke/city/Rcity4");
  /* setting desc */
  short_desc = "Central of Town";
  long_desc = "This is the central part of the town. In the middle\n"+
              "of the square you see some strange kind of light.\n"+
              "This must be what provides the dark elfs with their\n"+
              "power and illumination.\n";
}
