inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/darke/virtual/virtual_map";
  short_desc = "A enormous cave driven inside the mountain";
  long_desc = "It must have been a tough and sweaty job, making a big cave\n"+
              "as this is. Many workers have given their lives, making this\n"+
              "enormous cave. The ground, walls and ceiling is rough and\n"+
              "damp. It's rumoured to be a training ground for the dark\n"+
              "elves, who live in the city nearby.\n";
}

reset() {
  ::reset();
  if(!present("elf") && !random(3)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/delf"), this_object());
  }
  if(!present("elf") && !random(3)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/delf"), this_object());
  }
  if(!present("elf") && !random(3)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/delf"), this_object());
  }
}
