inherit "room/room";


reset(arg) {

  add_exit("north","/wizards/bulut/catacombs/room8");
  add_exit("east","/wizards/bulut/catacombs/room4");
  short_desc = "Ancient graveyard";
  long_desc = "You are standing on a peaceful grass field.\n" +
             "Another tombstone stands here. This graveyard looks a bit crowded.\n" +  
	     "Caretaker should really take a look at this part of the graveyard.\n" +
	     "It's very silent here, if you don't count the sounds that crows make.\n";

  set_light(2);                 
  items = allocate(2);


  if (!present("crow")) {
     move_object(clone_object("/wizards/bulut/catacombs/crow2"), this_object());
  }
                      
  items[0] = "tombstone";
  items[1] = "Plain old tombstone";


}
                                                          