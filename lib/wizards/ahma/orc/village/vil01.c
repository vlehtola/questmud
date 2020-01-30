inherit "room/room";

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/vil02");
  add_exit("southwest", "/wizards/ahma/orc/forest/for03");
  short_desc = "Entrance to village Nehelam";
  long_desc = "########### You have entered a village surrounded by a thick forest. The road\n" + 
              "#    |    # which leads to various places in the village is growing grass and\n" + 
              "#   ,*    # seems in every way badly maintained. In both sides of the road\n" + 
              "#  /      # there is growing green deciduous trees. The village is located in\n" + 
              "########### north and the exit is in south. A wooden sign is standing on the\n" +
              "            roadside.\n";

  items = allocate(2);
  items[0] = "sign";
  items[1] = "Welcome to peaceful village of Nehelam. The village is mainly habitated by\n" + 
             "Orcs, but if you are not an Orc and would still like to join our peaceful\n" + 
             "community, contact the village Chief whose hut is located in the northern\n" + 
             "part of the village. Thank you and have a great time among us!\n\n" + 
             "Some free maps of the village are hung on the sign. Type 'map' to see it\n" +
             "anytime in the village";
}

init() {
  ::init();
  add_action("map", "map");
  if(present("walkeri", this_object())) {
  call_other(present("walkeri", this_object()), "checkroom");
  }
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}
