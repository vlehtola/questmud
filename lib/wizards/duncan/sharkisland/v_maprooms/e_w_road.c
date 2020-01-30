inherit "room/outroom";

start() {
  mapfile = "/wizards/duncan/sharkisland/virtual_map";
  short_desc = "A road covered with sand, lined with small stones";
  long_desc = "A sandy and serpentine road is built on the island. It leads\n"+
              "towards east and west. The road leads to different destinations\n"+
              "and it's full of footprints. Small stones has been lined next to\n"+
              "the road, on both sides of the road.\n";

}
reset() {
  ::reset();
  if(!present("fisherman") && !random(5)) {
    move_object(clone_object("/wizards/duncan/sharkisland/monsters/fisherman.c"), this_object());
  }
}