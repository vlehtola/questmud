inherit "room/outroom";

start() {
  mapfile = "/wizards/irmeli/valley/virtual_map";
  short_desc = "Wandering in the swaying cornfield";
  long_desc = "Fold mountains are surrounding a verdant cornfield, which\n"+
              "grows in here. The yellow corn is tall and it sways, as\n"+
              "the wind blows. A grand mountain scenery reaches all the\n"+
              "way to the horizon, everwhere around the valley. A small\n"+
              "hill rises among the swaying cornfield.\n";
}
reset() {
  ::reset();
  if(!present("angel") && !random(5)) {
    move_object(clone_object("/wizards/irmeli/valley/monsters/angel2.c"), this_object());
  }
}

