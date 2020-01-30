inherit "room/room";

reset(arg) {
  if(arg) { return; }
  add_exit("cave", "/wizards/torspo/areat/gnomes/cave19.c");
  add_exit("west", "/wizards/torspo/areat/gnomes/hills17.c");
  short_desc = "Gnome city";
  long_desc = "You're walking at the bottom of a narrow path. Ancient river has carved this\n"+
              "huge scar in the mountain. Now the river has changed it's way and the path\n"+
              "is just an easy defendable entrance to the gnomish city. Some snow has piled\n"+
              "on the ground. To the east is mined a small entrance in the mountain.\n";
}
