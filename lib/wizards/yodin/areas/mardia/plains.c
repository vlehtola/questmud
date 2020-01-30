inherit "room/outroom";

start() {
mapfile = "/wizards/yodin/areas/mardia/virtual_map";
  short_desc = "Plains";
  long_desc = "Long grass grows all over the place as far as you can see.\n";

}

reset() {
  ::reset();
if(!present("bear") && !random(2)) {

move_object(clone_object("/wizards/yodin/areas/metsa/monsters/bear"), this_object());
  }

}
