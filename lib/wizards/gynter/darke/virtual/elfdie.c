inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/darke/virtual/virtual_map";
  short_desc = "A bonefilled underground sepulch";
  long_desc = "An underground sepulch is driven far away from the city. Its\n"+
              "purpoise is to keep the dead and the living apart from each\n"+
              "other. The ground is full of bones and dusty pieces of\n"+
              "clothes. There are recesses in the walls, reserved for the\n"+
              "dead bodies, but all of them are filled.\n";
}

reset() {
  ::reset();
  if(!present("elf") && !random(2)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/oldelf"), this_object());
  }
}
