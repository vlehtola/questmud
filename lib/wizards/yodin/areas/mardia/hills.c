inherit "room/outroom";

start() {
mapfile = "/wizards/yodin/areas/mardia/virtual_map";
  short_desc = "Small hills";
  long_desc = "Grass covers the hills surrounding you. Small trees grow\n"+
              "here and there. The vegetation seems to be concentrated\n"+
              "on the lower land and valleys.\n";




}

reset() {
  ::reset();
if(!present("bear") && !random(2)) {

move_object(clone_object("/wizards/yodin/areas/metsa/monsters/bear"), this_object());
  }

}
