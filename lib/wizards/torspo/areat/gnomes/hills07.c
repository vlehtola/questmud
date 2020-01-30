inherit "room/room";

reset(arg) {
 if(!present("farmer")) {
   move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/farmer1"), this_object());
   move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/farmer1"), this_object());
 }
 if(!present("pony")) {
   move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/pony1"), this_object());
 }

  if(arg) { return; }
  add_exit("south", "/wizards/torspo/areat/gnomes/hills03.c");
  add_exit("west", "/wizards/torspo/areat/gnomes/hills06.c");
  add_exit("north", "/wizards/torspo/areat/gnomes/hills13.c");
  short_desc = "Grassy hills";
  long_desc = "The path turns to west here. The ground is full of small footprints\n"+
              "and there's a broken plow lying in the bottom of the ditch. Far to the\n"+
              "west you see some stunted grain fields.\n";
  items = allocate(4);
  items[0] = "plow";
  items[1] = "The iron plow has broken in hard work. The ground is too rocky and icy\n"+
             "for raising";
  items[2] = "footprints";
  items[3] = "The ground is covered with small, gnomish made footprints";
}
