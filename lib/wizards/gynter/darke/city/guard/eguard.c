inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/darke/city/guard/virtual_guard_map";
  short_desc = "Guard Reception";
  long_desc = "The Reception hall of the Barracks.\n"+
		          "The walls are full of pictures of former\n"+
              "guardcaptains. One more uglier that the other.\n";
}

reset() {
  ::reset();
  if(!present("elf") && !random(8)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/elf"), this_object());
  }
  if(!present("lazy guard") && !random(8)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/lazy_guards"), this_object());
  }
}