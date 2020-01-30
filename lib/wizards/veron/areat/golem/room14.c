inherit "room/room";


reset(arg) {
    

add_exit("east","/wizards/veron/areat/golem/room13.c");

  short_desc = "The food storage";

  long_desc = "A small food storage with shelves full of food. An oil lamp\n"+
		  "gives some light to the room. It's quite cold in here and the place\n"+
		  "smells like a cellar. A large sack of potatoes has fallen off the\n"+
		  "shelf and its contents have spread on the floor.\n";


  items = allocate(6);
  items[0] = "lamp";
  items[1] = "An old oil lamp. It looks like it's going to run out of oil soon";
  items[2] = "shelves";
  items[3] = "The wooden shelves are full of food";
  items[4] = "sack";
  items[5] = "This sack has fallen out of the shelf";       

	set_not_out(1);	
  }