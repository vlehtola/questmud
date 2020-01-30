inherit "room/room";

reset(arg) {
  if(!present("ranger")) {
   move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/gnome1"), this_object());
   move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/gnome1"), this_object());
}
  if(arg) { return; }
  add_exit("south", "/wizards/torspo/areat/gnomes/hills07.c");
  add_exit("north", "/wizards/torspo/areat/gnomes/hills17.c");
  short_desc = "Grassy hills";
  long_desc = "The path rises up to the mountains. Air gets colder and it's hard to walk\n"+
              "up the rough and icy terrain. Small round rocks are slippery and start to\n"+
              "move as you walk on them. The stunted grass looks pathetic and boring.\n"+
              "Some decayed logs lie on the ground but no living tree is in sight.\n";
  items = allocate(2);
  items[0] = "logs";
  items[1] = "Some dead, decayed logs lie on the ground";
}
