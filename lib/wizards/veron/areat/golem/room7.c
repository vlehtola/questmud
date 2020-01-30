inherit "room/room";


object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/servant");
    move_object(monster, this_object());
  }

add_exit("stairs","/wizards/veron/areat/golem/room3.c");
add_exit("west","/wizards/veron/areat/golem/room8.c");
add_exit("east","/wizards/veron/areat/golem/room10.c");
add_exit("north","/wizards/veron/areat/golem/room12.c");

  short_desc = "A dimly lit corridor";

  long_desc = "This is a dimly lit corridor. A huge staircase leads downstairs from\n"+
		  "here. About half a dozen colorful pictures are hanging on the \n"+
		  "walls. A red carpet has been placed in the floor. The walls have\n"+
		  "some torch racks on them, but the torches in them are not lit.\n"+
		  "Some kind of a big hall can be seen in the end of this corridor.\n";
	  
		 
  items = allocate(6);
  items[0] = "pictures";
  items[1] = "Colorful pictures of flowers are hanging on the walls";
  items[2] = "carpet";
  items[3] = "An expensive-looking red carpet";
  items[4] = "racks";
  items[5] = "Some torch racks on the walls. The torches are not lit";	
set_not_out(1);	
set_light(2);

  }
