inherit "room/room";

reset(arg) {
  if(arg) { return; }
  add_exit("east", "/wizards/torspo/areat/gnomes/hills12.c");
  add_exit("northwest", "/wizards/torspo/areat/gnomes/hills16.c");
  short_desc = "Grassy hills";
  long_desc = "The conditions are getting too hard for the farming. There are some\n"+
              "cornfields located in the north but it's not so dense anymore. Small\n"+
              "path starts wandering to the northwest through the mountains.\n";
}
