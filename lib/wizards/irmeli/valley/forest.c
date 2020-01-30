inherit "room/outroom";

start() {
  mapfile = "/wizards/irmeli/valley/virtual_map";
  short_desc = "Forest";
  long_desc = "A tiny forest, that consist of leaf trees, old decayed\n"+
              "trees and stump of the trees. The ground is full of old,\n"+
              "rotten leaves from the nearby trees. A huge laurel tree\n"+
              "rises above tree line, from the middle of the forest. The\n"+
              "wind sways the trees dangerously, from side to side.\n";
}
reset() {
  ::reset();
  if(!present("angel") && !random(3)) {
    move_object(clone_object("/wizards/irmeli/valley/monsters/defector.c"), this_object());
  }
}

