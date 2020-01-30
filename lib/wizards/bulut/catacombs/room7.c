inherit "room/room";


reset(arg) {

  add_exit("south","/wizards/bulut/catacombs/room6");
  add_exit("north","/wizards/bulut/catacombs/room11");
  short_desc = "Ancient graveyard";
  long_desc = "You are standing on a peaceful grass field.\n" +
              "The gloomy atmosphere looks bit uncomfortable.\n" +
	      "Another tombstone is here. The wind makes humming sounds as it\n" +
              "passes the trees near by. No one seems to be taking care of this\n" +
              "old graveyard.\n";
  set_light(2);                 
  items = allocate(2);

  items[0] = "tombstone";
  items[1] = "A tombstone, no different from the others";



}
                                                          