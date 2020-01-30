inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/darke/city/hall/virtual_hall_map";
  short_desc = "Rows of benches";
  long_desc = "Almost endless rows with benches. You can easily\n"+
              "imagine that the entire population of the dark elfs\n"+
              "can find themself a place to sit in here.\n";
}

reset() {
  ::reset();
  if(!present("citizen") && !random(9)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/citizen"), this_object());
    move_object(clone_object("/wizards/gynter/darke/mobs/citizen"), this_object());
    move_object(clone_object("/wizards/gynter/darke/mobs/citizen"), this_object());
  } else {
    if(!present("citizen") && !random(4)) {
      move_object(clone_object("/wizards/gynter/darke/mobs/citizen"), this_object());
      move_object(clone_object("/wizards/gynter/darke/mobs/citizen"), this_object());
    } else {
      if(!present("citizen")) {
        move_object(clone_object("/wizards/gynter/darke/mobs/citizen"), this_object());
      }
    }
  }
}