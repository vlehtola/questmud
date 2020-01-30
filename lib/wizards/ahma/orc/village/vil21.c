inherit "room/room";

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/forest/for18");
  add_exit("south", "/wizards/ahma/orc/village/vil22");
  add_exit("west", "/wizards/ahma/orc/village/vil17");
  add_exit("east", "/wizards/ahma/orc/village/vil25");
  short_desc = "Entrance to village Nehelam";
  long_desc = "########### The Nuft street continues to west and east. In north can be seen an\n" + 
              "#    |    # entrance leading deeper inside the forest surrounding this small\n" + 
              "#+---*---+# village. In south is located the crossing-road between Nuft and\n" + 
              "#    |    # Sralk streets. A bigger hut can be seen over some distance in east.\n" + 
              "########### A worn wooden sign is lying fallen in the bank of a street.\n";

  items = allocate(2);
  items[0] = "sign";
  items[1] = "Welcome to peaceful village of Nehelam. The village is mainly habitated by\n" + 
             "Orcs, but if you are not an Orc and would still like to join our peaceful\n" + 
             "community, contact the village Chief whose hut is located in east from here.\n" + 
             "Thank you and have a great time among us!\n\n" + 
             "Some free maps of the village are scattered in the ground. Type 'map' to see it\n" +
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
