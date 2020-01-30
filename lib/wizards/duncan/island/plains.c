inherit "room/outroom";

start() {
  mapfile = "/wizards/duncan/island/virtual_map";
  short_desc = "Plains, covered with windswept grass";
  long_desc = "A low, windswept grass lawn is covering the ground. The\n"+
              "grass is mostly brown-coloured, typical leathery grass,\n"+
              "which grows on islands. The wind blows strongly from the\n"+
              "sea, beating the grass. A thick and wet mist is floating\n"+
              "over the island, blanketing the whole view to the sea.\n";
}
reset() {
  ::reset();
  if(!present("man") && !random(10)) {
    move_object(clone_object("/wizards/duncan/island/monsters/man.c"), this_object());
  }
}

