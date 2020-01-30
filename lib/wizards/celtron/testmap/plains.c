inherit "room/outroom";

start() {
  mapfile = "/wizards/celtron/field/virtual_map";
  short_desc = "Plains";
  long_desc = "Grass covers all the ground.\n";
}
reset() {
  ::reset();
  if(!present("fox") && !random(4)) {
    move_object(clone_object("/wizards/celtron/field/fox"), this_object());
  }
}

