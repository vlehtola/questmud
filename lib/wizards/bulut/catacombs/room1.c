inherit "room/room";


reset(arg) {

  add_exit("north","/wizards/bulut/catacombs/room2");
  add_exit("out","out: 34 135");
  short_desc = "Ancient graveyard";
  long_desc = "You are standing on a peaceful grass field.\n" +
	      "Only the wind blowing in the trees breaks the silence.\n" +
              "The gloomy atmosphere looks a bit uncomfortable.\n" +
	      "Small old tombstone is here, waiting for collapsing.\n" +  
              "No one seems to be taking care of this old graveyard.\n";
  set_light(2);                 
  items = allocate(2);

  items[0] = "tombstone";
  items[1] = "Just an old tombstone";      



}
                                                          