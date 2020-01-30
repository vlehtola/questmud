inherit "room/room";

reset(arg) {
  add_exit("down", "/wizards/ahma/castle/rooms/area09a");
  add_exit("up", "/wizards/ahma/castle/rooms/area10");
  short_desc = "At the staircase";
  long_desc = "Climbing the narrow staircase.\n" + 
              "The narrow, stony staircase leads up to the watch tower and down to the\n" + 
              "guarding post. Staircase is made of stones attached to each other, but\n" + 
              "the stairs have been grinded into a smooth, almost beautiful, mass. There\n" + 
              "are no windows along the way and the torches which are supposed to light up\n" + 
              "the way have been extinguished by someone or something, the staircase gets\n" + 
              "some luminance from upstairs where the watch tower is.\n";
}
