inherit "room/room";
reset(arg) {
if(arg) return;
add_exit("south","/wizards/veron/areat/cotd/street2.c");
add_exit("north","/wizards/veron/areat/cotd/cs.c");
add_exit("west","/wizards/veron/areat/cotd/bakery.c");
add_exit("east","/wizards/veron/areat/cotd/stable.c");

  short_desc = "Main street";

  long_desc = "The main street is of this town is very narrow. The wind\n"+
              "twirling around the wooden shacks brings dust from the\n"+
	      "plains making it hard to breathe. Two skeletons hanged\n"+
              "in a single pirch wobble in the wind in the middle of the\n"+
	      "street. There's also a corpse lying on the ground under\n"+
	      "the tree. The shack in the western side of the road looks\n"+
	      "like a bakery, and the big building one in the eastern side\n"+
	      "is no doubt a stables.\n";
              

  items = allocate(6);
  items[0] = "skeletons";
  items[1] = "Three skeletons hang from a pirch in the middle of the street. The legs have\n"+
             " been chopped off";
  items[2] = "corpse";
  items[3] = "A partly-eaten corpse of a man. There are arrows sticking ouf from it's back";
  items[4] = "bakery";
  items[5] = "The miserable-looking bakery has no doubt seen better days";

 	
  }
