inherit "room/room";

reset(arg) {
  if(!present("guard")) {
   move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/guard1"), this_object());
}
  if(arg) { return; }
  add_exit("south", "/wizards/torspo/areat/gnomes/hills13.c");
  add_exit("east", "/wizards/torspo/areat/gnomes/hills18.c");
  add_exit("northwest", "/wizards/torspo/areat/gnomes/hills23.c");
  short_desc = "Gnome village entrance";
  long_desc = "A small guard post is built here. This is the last opportunity to stop\n"+
              "the possible invaders. Narrow path starts wandering to the east. You notice\n"+
              "a small cave entrance over there. It is rumoured that the gnome city is\n"+
              "built under the mountain. The rocky ground seems to be used a lot. It's\n"+
              "slippery and shabby.\n";
}
