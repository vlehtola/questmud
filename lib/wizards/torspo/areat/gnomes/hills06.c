inherit "room/room";

reset(arg) {
 if(!present("farmer")) {
   move_object(clone_object("/wizards/torspo/areat/gnomes/monsters/farmer1"), this_object());
 }
  if(arg) { return; }
  add_exit("west", "/wizards/torspo/areat/gnomes/hills05.c");
  add_exit("east", "/wizards/torspo/areat/gnomes/hills07.c");
  short_desc = "Gnomish fields";
  long_desc = "The large gnomish grain fields open all around you. It is hard to\n"+
              "believe that any plants like these manage to live in this environment.\n"+
              "The rocks have been gathered and piled in a huge heap. Some trees have\n"+
              "been planted here so that the snow, rain and wind don't ruin the crop.\n";
  items = allocate(2);
  items[0] = "trees";
  items[1] = "These sturdy trees are able to live in these conditions. They protect the crop "+
             "against the wind";
}
