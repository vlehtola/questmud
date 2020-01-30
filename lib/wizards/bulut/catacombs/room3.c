inherit "room/room";


reset(arg) {

  add_exit("north","/wizards/bulut/catacombs/room4");
  add_exit("south","/wizards/bulut/catacombs/room2");
  short_desc = "Ancient graveyard";
  long_desc = "You are standing on a peaceful grass field.\n" +
	      "The grass has been cut here shortly, perhaps the caretaker\n" +
	      "has snipped it with his stale hands. The view does not however \n" +
              "look impressing. The gloomy atmosphere looks a bit uncomfortable.\n" +
	      "Iron bench stands here.\n";
  set_light(2);                 
  items = allocate(2);


  if (!present("caretaker")) {
     move_object(clone_object("/wizards/bulut/catacombs/caretaker"), this_object());
  }
                      
  items[0] = "bench";
  items[1] = "Rusty old iron bench";


}
                                                          