inherit "room/room";
reset(arg) {
if(arg) return;

add_exit("out","/wizards/veron/areat/cotd/cs.c");

  short_desc = "The general store";

  long_desc = "The general store  is a one-room house with wooden shelves all\n"+
	      "around the room. There's a wooden desk with an acabus on it\n"+
              "for the business. All the shelves are empty, there are only\n"+
              "some wooden toys left. The house is all dusty and there are\n"+
              "huge holes in the ceiling.\n";
       set_not_out(1);        
  items = allocate(8);
  items[0] = "shelves";
  items[1] = "Some plain looking wooden shelves for storing the goods";
  items[2] = "desk";
  items[3] = "A large wooden desk. There's an acabus on it";
  items[4] = "acabus";
  items[5] = "An acabus for summing the money";
  items[6] = "toys";
  items[7] = "Some wooden toys. A ball and a toy sword";

 	
  }
