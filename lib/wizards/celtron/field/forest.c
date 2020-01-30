inherit "room/outroom";

start() {
  mapfile = "/wizards/celtron/field/virtual_map";
  short_desc = "Forest";
  long_desc = "A quite dense forest contains all kinds of trees.\n";
}

reset() {
  ::reset();
  if(!present("bear") && !random(3)) {
    move_object(clone_object("/wizards/celtron/field/bear"), this_object());
  }
}

