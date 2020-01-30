inherit "room/room";


reset(arg) {

  add_exit("east","/wizards/bulut/catacombs/room10");
  add_exit("south","/wizards/bulut/catacombs/room8");
  short_desc = "Ancient graveyard";
  long_desc = "You are standing on a peaceful grass field.\n" +
              "The wind makes humming sounds as it passes the trees near by.\n" +
	      "Another tombstone stands here. A big monument can be seen on eastwards.\n" +  
              "No one seems to be taking care of this old graveyard.\n";
  set_light(2);                 
  items = allocate(4);

  items[0] = "tombstone";
  items[1] = "A tombstone, no different from the others";
  items[2] = "monument";
  items[3] = "A big monument, You might want to move your ass to east for closer inpection.";
}
                                                          