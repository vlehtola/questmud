inherit "room/outroom";

start() {
  mapfile = "/wizards/gynter/darke/virtual/virtual_map";
  short_desc = "A road to the city";
  long_desc = "Between the high mountains is built a road, which leads to the\n"+
              "city. The road is paved with sand, ringed with big circular\n"+
              "stones and set out with hedges. The hedges are full of blue\n"+
              "berries, poison berries. Above the mountains, can be seen the\n"+
              "sky. The road is old, but in very good condition.\n";
}

reset() {
  ::reset();
  if(!present("worker") && !random(3)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/worker"), this_object());
  }
  if(!present("worker") && !random(3)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/worker"), this_object());
  }
  if(!present("worker") && !random(3)) {
    move_object(clone_object("/wizards/gynter/darke/mobs/worker"), this_object());
  }
}
