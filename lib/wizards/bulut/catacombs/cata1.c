inherit "room/room";


reset(arg) {

  add_exit("north","/wizards/bulut/catacombs/cata3");
  add_exit("south","/wizards/bulut/catacombs/cata2");
  add_exit("west","/wizards/bulut/catacombs/cata4");
  short_desc = "Catacombs";
  long_desc = "You are wandering somewhere under the graveyard.\n" +
	      "Smell of rotten flesh is coming from the graves near by.\n" +	
	      "The ground is hard, but moisty. You wonder why do these catacombs exist.\n" +     
              "This place makes you feel distressed.\n";
  set_light(1);                 


}
                    
