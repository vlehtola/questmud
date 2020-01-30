inherit "room/outroom";

start() {
  mapfile = "/wizards/irmeli/meadow/virtual_map.c";
  short_desc = "Grassfield";
  long_desc = "The tall, green grass is swaying in the wind, making billowy move. The grass\n"+
              "is growing everywhere, forming a big grassfield around you, reaching all the\n"+
              "way to the horizon. The fertile soil gives the best growth milieu for the\n"+
              "grass.\n";
}
reset() {
  ::reset();
  if(!present("rabbit") && !random(4)) {
    move_object(clone_object("/wizards/irmeli/meadow/monsters/rabbit.c"), this_object());
  }
}

