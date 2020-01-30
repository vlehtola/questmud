inherit "room/outroom";
reset() {
  ::reset();
  if(!present("rabbit 3") && !random(1)) {
  move_object(clone_object("/wizards/siki/island/monsters/rabbit"), this_object());
  }
}

start() {
  mapfile = "/wizards/siki/island/v_map";
  short_desc = "Bushes";
  long_desc = "Some bushes are growing here. Some of them are almost\n"+
              "entirely eaten up and there are huge amounts of grass\n"+
              "missing.\n";
}


