inherit "room/outroom";

start() {
  mapfile = "/wizards/duncan/sharkisland/virtual_map";
  short_desc = "A forest full of softwoods";
  long_desc = "The forest consists of softwoods like spruces and pines. It's\n"+
              "really hard to see ahead because there are trees standing next\n"+
              "to next. The ground is full of big roots and rotten cones.\n"+
              "Couple pines has fell down to the ground and they have started\n"+
              "to decompose.\n";
}
reset() {
  ::reset();
  if(!present("sailor") && !random(5)) {
    move_object(clone_object("/wizards/duncan/sharkisland/monsters/sailor.c"), this_object());
  }
}
