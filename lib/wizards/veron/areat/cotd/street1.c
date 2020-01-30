inherit "room/room";
reset(arg) {
if(arg) return;
add_exit("north","/wizards/veron/areat/cotd/street2.c");
add_exit("hills","outmap: 120 83");


  short_desc = "Main street";

  long_desc = "You're standing in the main street of a small and dusty\n"+
              "mining town. The so-called main street is only some ten feet\n"+
	      "wide. The whirling and howling  wind blows sand from the plains\n"+
              "making air uncomfortable to breath. Some large buildings can\n"+
	      "be seen in the northwest and northeast. A large sign lies in\n"+
	      "the ground.\n";
              

  items = allocate(4);
  items[0] = "buildings";
  items[1] = "Some large buildings. The one in northeast looks like an inn of some kind";
  items[2] = "sign";
  items[3] = "The sign reads:'Welcome to Remick. Population: 52'";
 	
  }
