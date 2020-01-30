inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/darke/virtual/virtual_map";
  short_desc = "A narrow tunnel";
  long_desc = "A very narrow tunnel runs inside the mountain, leading\n"+
              "deeper in the bowels of earth. There is barely room\n"+
              "enough to walk in here. At some places, the tunnel is\n"+
              "so low, that you need to crawl to get ahead. It looks\n"+
              "like this tunnel is frequently in use.\n";
}

reset() {
  ::reset();
  if(!present("elf") && !random(8)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/elf"), this_object());
  }
  if(!present("elf") && !random(6)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/elf"), this_object());
  }
  if(!present("elf") && !random(7)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/elf"), this_object());
  }
}
