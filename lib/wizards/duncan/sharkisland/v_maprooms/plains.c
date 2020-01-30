inherit "room/outroom";

start() {
  mapfile = "/wizards/duncan/sharkisland/virtual_map";
  short_desc = "Plains full of grass and cactuars";
  long_desc = "Short grass and cactuars are growing in the plains. The soil\n"+
              "on the island seems dry but fertile. The grass is a bit brown\n"+
              "for some strange reason. The spines in the cactuars are sharp\n"+
              "and therefore very deadly.\n";
}
reset() {
  ::reset();
  if(!present("gull") && !random(10)) {
    move_object(clone_object("/wizards/duncan/sharkisland/monsters/gull.c"), this_object());
  }
}

