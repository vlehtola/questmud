inherit "room/room";

int i;

reset(arg) {

  add_exit("out","/wizards/bulut/catacombs/cata5");
  short_desc = "Catacombs";
  long_desc = "This little room looks quite nice, comparing the catacombs where you came in.\n" +
	      "The smell of rotten flesh is still here, but somehow you feel a bit lighter.\n"; 
  set_light(1);                 

  if (!present("rat")) {
     move_object(clone_object("/wizards/bulut/catacombs/rat"), this_object());
	  }

	if(!i) {
	move_object(clone_object("/wizards/bulut/catacombs/parchment"), this_object());
  	i=1;
	}
}
                                                          