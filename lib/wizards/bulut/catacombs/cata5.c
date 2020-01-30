inherit "room/room";


reset(arg) {

  add_exit("south","/wizards/bulut/catacombs/cata3");
  short_desc = "Catacombs";
  long_desc = "You are wandering somewhere under the graveyard.\n" +
	      "Smell of rotten flesh is coming from the graves near by.\n" +	
	      "The ground is hard, but moisty. You wonder why do these catacombs exist.\n" +     
              "This place makes you feel distressed.\n";
  set_light(1);                 

  if (!present("girl")) {
     move_object(clone_object("/wizards/bulut/catacombs/girl"), this_object());
	  }

}
                                                          
