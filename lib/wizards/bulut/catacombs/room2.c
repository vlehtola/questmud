inherit "room/room";


reset(arg) {

  add_exit("north","/wizards/bulut/catacombs/room3");
  add_exit("south","/wizards/bulut/catacombs/room1");
  short_desc = "Ancient graveyard";
  long_desc = "You are standing on a peaceful grass field.\n" +
              "The gloomy atmosphere looks a bit uncomfortable.\n" +
	      "A big monument is standing here.\n" +  
              "No one seems to be taking care of this old graveyard.\n";
  set_light(2);                 
  items = allocate(2);

  items[0] = "monument";
  items[1] = "A big monument standing for the brave men who died\n" +
	     "in some great battle long time ago";       



}
                                                          