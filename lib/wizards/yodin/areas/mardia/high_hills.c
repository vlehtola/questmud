inherit "room/outroom";

start() {
mapfile = "/wizards/yodin/areas/mardia/virtual_map";
  short_desc = "High hills";
  long_desc = "Hills of great height dominate the area as far the eye can see.\n"+
              "Vegetation is quite rare, some plants grow on the lower hillsides.\n"+
              "Some peaks seem to have snow or ice cover.\n";




}

reset() {
  ::reset();
if(!present("bear") && !random(2)) {

move_object(clone_object("/wizards/yodin/areas/metsa/monsters/bear"), this_object());
  }

}
