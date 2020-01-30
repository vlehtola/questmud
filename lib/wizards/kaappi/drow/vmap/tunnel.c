inherit "room/outroom";

start() {
  mapfile = "/wizards/kaappi/drow/vmap/virtual_map";

  short_desc = "A small tunnel";
  long_desc = "A quite small tunnel. Some strange mushrooms\n"+
              "are growing on the walls and ground. These mushrooms\n"+
              "are glowing dimly, giving a little blue light\n"+
              "to the tunnel. You sense that an immense evil\n"+
              "is living in this dark tunnel.\n";


}
reset() {
  ::reset();
  if(!present("orja") && !random(3)) {
  move_object(clone_object("/wizards/kaappi/drow/mobs/orjat"), this_object());
 }
}
