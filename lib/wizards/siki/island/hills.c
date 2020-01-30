inherit "room/outroom";
reset() {
  ::reset();
  if(!present("giant 2") && !random(3)) {
  move_object(clone_object("/wizards/siki/island/monsters/hgiant"), this_object()
);
  }
}


start() {
  mapfile = "/wizards/siki/island/v_map";
  short_desc = "Hills";
  long_desc = "Small rough hills with some vegetation. The small round\n"+
              "rocks cover the ground entirely and only the toughest\n"+
              "plants have survived.\n";
}

