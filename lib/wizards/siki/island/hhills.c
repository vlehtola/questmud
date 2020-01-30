inherit "room/outroom";
reset() {
  ::reset();
  if(!present("giant 1") && !random(2)) {
  move_object(clone_object("/wizards/siki/island/monsters/hgiant"), this_object()
);
  }
}


start() {
  mapfile = "/wizards/siki/island/v_map";
  short_desc = "High hills";
  long_desc = "Rocky hills with no plants. The huge rocks makes is almost\n"+
              "impossible to move quickly.\n";
}

