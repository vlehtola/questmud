inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/darke/city/guard/virtual_guard_map";
  short_desc = "Sleeping Chambers";
  long_desc = "The grand sleeping chambers of the Guards.\n"+
              "The room is packed with beds, some occupied others not.\n";
}

reset() {
  ::reset();
  if(!present("lazy guard") && (random(8) >= 5)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/lazy_guards"), this_object());
    move_object(clone_object("/wizards/gynter/darke/mobs/lazy_guards"), this_object());
    move_object(clone_object("/wizards/gynter/darke/mobs/lazy_guards"), this_object());
    move_object(clone_object("/wizards/gynter/darke/mobs/lazy_guards"), this_object());
  } else if(!present("lazy guard") && (random(8) == 3)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/lazy_guards"), this_object());
    move_object(clone_object("/wizards/gynter/darke/mobs/lazy_guards"), this_object());
    move_object(clone_object("/wizards/gynter/darke/mobs/lazy_guards"), this_object());
  } else if(!present("lazy guard")) {
    move_object(clone_object("/wizards/gynter/darke/mobs/lazy_guards"), this_object());
  }
}