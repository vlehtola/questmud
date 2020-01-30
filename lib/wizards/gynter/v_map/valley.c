inherit "room/outroom";

start() {
  mapfile = "/wizards/celtron/field/virtual_map";
  short_desc = "Valley";
  long_desc = "Mountains raise from both sides of the valley.\n";
}

reset() {
  ::reset();
  if(!present("cyclop") && !random(5)) {
    move_object(clone_object("/wizards/celtron/field/cyclop"), this_object());
  }
}
