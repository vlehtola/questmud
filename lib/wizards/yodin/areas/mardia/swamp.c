inherit "room/outroom";

start() {
mapfile = "/wizards/yodin/areas/mardia/virtual_map";
  short_desc = "Swamp";
  long_desc = "Flat land has stored a lot of water in it's muddy pockets\n"+
              "forming a swamp. The wind smells bitter carrying the odor\n"+
              "of rotting plants.\n";



}

reset() {
  ::reset();
if(!present("bear") && !random(2)) {

move_object(clone_object("/wizards/yodin/areas/metsa/monsters/bear"), this_object());
  }

}
