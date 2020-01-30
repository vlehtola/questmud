inherit "room/room";
int mob;

reset(arg) {
  add_exit("northwest", "/wizards/ahma/orc/village/vil23");
  add_exit("northeast", "/wizards/ahma/orc/forest/for31");
  add_exit("southwest", "/wizards/ahma/orc/village/vil07");
  short_desc = "Entrance to village Nehelam";
  long_desc = "########### Sralk and Galor streets begin from here. The Sralk street leads to\n" + 
             "#   \\  /  # northwest and the Galor street to southwest. To northeast is the\n" + 
              "#    *'   # entrance to the thick forest which seems to surround the village.\n" + 
              "#   /     # The forest mainly consists of green deciduous trees. A crappy-\n" + 
              "########### looking wooden sign is standing almost in a bush near the roadside.\n";

  items = allocate(2);
  items[0] = "sign";
  items[1] = "Welcome to peaceful village Nehelam. The village is mainly habitated by\n" + 
             "Orcs, but if you are not an Orc and would still like to join our peaceful\n" + 
             "community, contact the village Chief whose hut is located in northwest from\n" + 
             "here. Thank you and have a great time among us!\n\n" + 
             "Some free maps of the village are hung on the sign. Type 'map' to see it\n" +
             "anytime in the village";

  if(mob < 1) { move_object(clone_object("/wizards/ahma/orc/mob/man"), this_object()); mob++; }
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

childdead() {
  mob--;
}
