inherit "room/room";


reset(arg) {

  add_exit("north","/wizards/bulut/catacombs/room13");
  add_exit("south","/wizards/bulut/catacombs/room10");
  short_desc = "Ancient graveyard";
  long_desc = "You are standing on a peaceful grass field.\n" +
	      "Some dark presence can be sensed in north.\n" +	
	      "Caretaker should really take a look at this part of the graveyard.\n" +     
              "This part of the graveyard is in terrible condition.\n";
  set_light(2);                 


}
                                                          