inherit "room/room";
reset(arg) {
if(arg) return;

add_exit("out","/wizards/veron/areat/cotd/street3.c");

  short_desc = "Bakery";

  long_desc = "The bakery is a one-room house with wooden shelves all around\n"+
	      "the room. A large oven made of bricks is built in the northern\n"+
              "part of the room. There's also a wooden desk with an acabus on it\n"+
              "for the business. Remnants of rotting food can be seen on the\n"+
              "desk and on the shelves. The rats have had their part of it too,\n"+
              "by the looks of this room. There are plates and baking sheets all\n"+
              "over the floor.\n";
               set_not_out(1);
  items = allocate(16);
  items[0] = "shelves";
  items[1] = "Some plain looking wooden shelves for storing the goods";
  items[2] = "oven";
  items[3] = "A large oven bade of bricks. It's placed next to the northern wall";
  items[4] = "desk";
  items[5] = "A large wooden desk. There's an acabus on it";
  items[6] = "acabus";
  items[7] = "An acabus for summing the money";
  items[8] = "food";
  items[9] = "Blackened rotting remnants of food";
  items[10] = "plates";
  items[11] = "Nice plates with pictures of flowers in them";
  items[12] = "baking sheets";
  items[13] = "Baking sheets made of iron. They're all rusty now";
  items[14] = "sheets";
  items[15] = "Baking sheets made of iron. They're all rusty now";

 	
  }
