inherit "room/outroom";
reset() {
  ::reset();
  if(!present("giant 2") && !random(2)) {
  move_object(clone_object("/wizards/siki/island/monsters/giant"), this_object());
  }
}


start() {
  mapfile = "/wizards/siki/island/v_map";
  short_desc = "Plains";
  long_desc = "Green plains full of huge footprints. The ground is\n"+
              "soft and there is some grass missing here and there.\n";
}


