inherit "room/room";

reset(arg) {
  if(arg) { return; }
  add_exit("out", "/wizards/torspo/areat/gnomes/hills18.c");
  add_exit("east", "/wizards/torspo/areat/gnomes/cave20.c");
  add_exit("south", "/wizards/torspo/areat/gnomes/cave14.c");

  set_not_out(1);
  set_light(2);
  short_desc = "gnomish city";
  long_desc = "This underground tunnel has been mauled in the hard, icy mountain. It seems\n"+
              "to be very old and the angular shapes have softened during the\n"+
              "centuries of erosion. Some dust is lying on the ground and there are lots\n"+
              "of small footsteps in it. Some weird looking stones on the wall shine\n"+
              "gray dim light over the whole room.\n";
  items = allocate(6);
  items[0] = "stones"; 
  items[1] = "They light up the place with their dim gray light";
  items[2] = "footsteps";
  items[3] = "Small footsteps. Probably made by gnome shoes";
  items[4] = "wall";
  items[5] = "There are some shimmering gray stones on the rocky wall";
}
