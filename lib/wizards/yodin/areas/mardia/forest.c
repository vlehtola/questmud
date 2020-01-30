inherit "room/outroom";

start() {
mapfile = "/wizards/yodin/areas/mardia/virtual_map";
  short_desc = "Small forest";
  long_desc =  "Trees are growing here and there, somewhat slowing\n"+
        "the your movement. You can see the sky above you\n"+
          "and hear the sounds of various animals. There is a\n"+
              "multitude of plants and other flora growing here.\n";




}

reset() {
  ::reset();
if(!present("bear") && !random(2)) {

move_object(clone_object("/wizards/yodin/areas/metsa/monsters/bear"), this_object());
  }

}
