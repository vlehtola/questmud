inherit "room/outroom";

start() {
  mapfile = "/wizards/irmeli/valley/virtual_map";
  short_desc = "Valley";
  long_desc = "A lush valley is full of multicolored, verdant flowers,\n"+
              "and fresh, green grass, which has been mown. The soil is\n"+
              "fertile, offering the best growth milieu for the living\n"+
              "things. The massive fold mountains surrounds the beatiful\n"+
              "valley. The valley is a piece of unspoiled nature.\n";
}
reset() {
  ::reset();
  if(!present("angel") && !random(6)) {
    move_object(clone_object("/wizards/irmeli/valley/monsters/slave.c"), this_object());
  }
}

