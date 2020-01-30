inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/darke/city/hall/virtual_hall_map";
  short_desc = "The Back of the Hall";
  long_desc = "This is the place where the less fortunate\n"+
              "of the Dark Elf's have to stand if the want\n"+
              "to follow the proceedings.\n";
}

reset() {
  ::reset();
  if(!present("citizen") && !random(5)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/citizen"), this_object());
  }
  if(!present("citizen") && !random(5)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/citizen"), this_object());
  }
  if(!present("citizen") && !random(5)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/citizen"), this_object());
  }
}