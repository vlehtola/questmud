inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/darke/city/guard/virtual_guard_map";
  short_desc = "Training Grounds";
  long_desc = "The Training Grounds.\n"+
		          "Here you can see the guards that isn't on duty nor sleeping.\n"+
              "They are all here training. Even the masters.\n";
}

reset() {
  ::reset();
  if(!present("delf") && !random(8)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/delf"), this_object());
    move_object(clone_object("/wizards/gynter/darke/mobs/delf"), this_object());
    move_object(clone_object("/wizards/gynter/darke/mobs/delf"), this_object());
  }
}