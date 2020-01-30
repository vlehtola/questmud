inherit "room/outroom";

start() {
mapfile = "/wizards/yodin/areas/mardia/virtual_map";
  short_desc = "Old Forest";
  long_desc = "High trees surround you at every direction.\n"+
              "Pine trees have grown into dense stacks here and there\n"+
              "efficiently blocking out light.\n";

}

reset() {
  ::reset();
if(!present("bear") && !random(2)) {

move_object(clone_object("/wizards/yodin/areas/metsa/monsters/bear"), this_object());
  }

}
