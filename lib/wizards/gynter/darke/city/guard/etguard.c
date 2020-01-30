inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/darke/city/guard/virtual_guard_map";
  short_desc = "A narrow tunnel";
  long_desc = "Very narrow tunnel. There is barely room enough for\n"+
		          "you to walk in here. But as you look around you see\n"+
              "that this tunnel is frequently used.\n";
}

reset() {
  ::reset();
  if(!present("worker") && (random(8) >= 3)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/worker"), this_object());
  }
}