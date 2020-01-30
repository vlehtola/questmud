inherit "room/room";

reset(arg) {
 if(!present("ranger")) {
  move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/gnome1"), this_object());
}

  if(arg) { return; }
  add_exit("east", "/wizards/torspo/areat/gnomes/hills22.c");
  add_exit("southwest", "/wizards/torspo/areat/gnomes/hills16.c");

  short_desc = "Gnomish mountains";
  long_desc = "Small canyon starts vailing through the mountain to the southwest. An old,\n"+
              "collapsed hut lies beside the western mountain wall. Some small wooden\n"+
              "crosses have been placed around the hut.\n";
  items = allocate(4);
  items[0] = "crosses";
  items[1] = "Wooden crosses mark the places of the gnomes' graves";
  items[2] = "hut";
  items[3] = "Burnt, wooden hut. Some evil monsters from the mountains have demolished\n"+
             "it and killed the inhabitants";
}
