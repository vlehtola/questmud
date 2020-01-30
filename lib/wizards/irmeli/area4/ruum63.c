inherit "room/room";  

reset(arg) {
  add_exit("north","/wizards/irmeli/area4/ruum61.c");
  add_exit("south","/wizards/irmeli/area4/ruum65.c");

  short_desc = "On a balcony at top of the Orthanc, tower of death";
  long_desc = "You are standing on a balcony, which is made from wood. It goes round the\n"+
                "tower. There is exits to south and north if you want to take sightseeing\n"+
                "around the tower. You can't even see the ground from here, because the air\n"+
                "is heavy and misty.\n";
}
