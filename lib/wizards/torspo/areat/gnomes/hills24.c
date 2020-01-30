inherit "room/room";

reset(arg) {
  if(arg) { return; }
  add_exit("northeast", "/wizards/torspo/areat/gnomes/hills26.c");
  add_exit("south", "/wizards/torspo/areat/gnomes/hills22.c");
  short_desc = "Gnomish mountains";
  long_desc = "Path starts climbing up to the mountains. From here can be seen the lower\n"+
              "parts of the mountain. No living thing is in sight but there are some footprints\n"+
              "of wolves on the ground. The snow has piled in the huge drifts in the upper\n"
              "parts of the mountain.\n";
}
