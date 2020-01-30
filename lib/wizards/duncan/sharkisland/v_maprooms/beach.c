inherit "room/outroom";

start() {
  mapfile = "/wizards/duncan/sharkisland/virtual_map";
  short_desc = "Beach covered with fine sand";
  long_desc = "A sandy beach on the island. There is fine sand everywhere.\n"+
              "Coconut palms are growing here and there on the beach.\n"+
              "Among the sand is lying couple coconuts which are cut in\n"+
              "two. The water is full of dangerous blue-seaweed rafts.\n";
}
reset() {
  ::reset();
  if(!present("monkey") && !random(5)) {
    move_object(clone_object("/wizards/duncan/sharkisland/monsters/monkey.c"), this_object());
  }
}

