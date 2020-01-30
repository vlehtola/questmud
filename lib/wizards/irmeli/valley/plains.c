inherit "room/outroom";

start() {
  mapfile = "/wizards/irmeli/valley/virtual_map";
  short_desc = "Plains";
  long_desc = "Tall, green grass is growing everywhere, forming a big\n"+
              "grassfield in the valley, reaching all the way to the\n"+
              "horizon. The grass is swaying in the wind, making\n"+
              "billowy move. The surrounding fold mountains are\n"+
              "rising up to the sky, like a skycrapers.\n";
}
reset() {
  ::reset();
  if(!present("angel") && !random(7)) {
    move_object(clone_object("/wizards/irmeli/valley/monsters/angel.c"), this_object());
  }
}

