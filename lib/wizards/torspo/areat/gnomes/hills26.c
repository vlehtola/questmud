inherit "room/room";

reset(arg) {
 if(!present("wolf")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/beast1"), this_object());
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/beast1"), this_object());
 }

  if(arg) { return; }
  add_exit("northeast", "/wizards/torspo/areat/gnomes/hills27.c");
  add_exit("southwest", "/wizards/torspo/areat/gnomes/hills24.c");
  add_exit("hole", "/wizards/torspo/areat/gnomes/hole.c");

  short_desc = "Mountains";
  long_desc = "The way still climbs up the mountain. Path is snowy, tight and hard to walk.\n"+
              "Small canyon-like way continues to northeast where can be seen high\n"+
              "rising walls. At the right side of the path is a small hole in the\n"+
              "rock, formed probably by the nature.\n";
  items = allocate(2);
  items[0] = "hole";
  items[1] = "Hole, formed by erosion, serves now as a home for a pack of wolves";
}
