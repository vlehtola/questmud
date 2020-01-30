inherit "room/room";  

reset(arg) {
  add_exit("west","/wizards/irmeli/area4/ruum56.c");
  add_exit("east","/wizards/irmeli/area4/ruum57.c");
  add_exit("south","/wizards/irmeli/area4/ruum48.c");

  short_desc = "On a balcony at top of the Orthanc, tower of death";
  long_desc = "You are standing on a balcony, which is made from wood. It goes round the\n"+
                "tower. There is exits to west, east and south if you want to take\n"+
                "sightseeing around the tower. When you have been long inside the tower\n"+
                "the fresh air feels and smells better than ever.\n";
}

