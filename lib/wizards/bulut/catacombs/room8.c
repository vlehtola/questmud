inherit "room/room";


reset(arg) {

  add_exit("south","/wizards/bulut/catacombs/room5");
  add_exit("north","/wizards/bulut/catacombs/room9");
  short_desc = "Ancient graveyard";
  long_desc = "You are standing on a peaceful grass field.\n" +
              "Only the wind blowing in the trees breaks the silence.\n" +
	      "Another tombstone is here, almost collapsing.\n" +  
              "No one seems to be taking care of this old graveyard.\n";
  set_light(2);                 
  items = allocate(2);

  items[0] = "tombstone";
  items[1] = "A tombstone, no different from the others";



}
                                                          