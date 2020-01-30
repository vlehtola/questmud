inherit "room/room";


object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/summoner");
    move_object(monster, this_object());
  }

add_exit("east","/wizards/veron/areat/golem/room7.c");
add_exit("ladder","/wizards/veron/areat/golem/room9.c");

  short_desc = "Small workroom";

  long_desc = "This place looks like a workroom. There are papers everywhere.\n"+
		  "Large bookshelves full of books conceal the walls and windows.\n"+
		  "A wooden desk is in the northwestern corner. Small candles are\n"+
		  "burning on the desk, giving dim light to the room. A skull is\n"+
		  "placed on the desk. A ladder leads to a hatch in the ceiling\n"+
		  "of this room.\n";
		 
  items = allocate(10);
  items[0] = "papers";
  items[1] = "Papers with some notes in them. The hand-writing is awful,\n"+ 
             "you can't read it";
  items[2] = "books";
  items[3] = "Some magic books with pentagrams in their covers. You don't\n"+
             "understand the text in them";
  items[4] = "hatch";
  items[5] = "A wooden hatch. It's not locked";
  items[6] = "desk";
  items[7] = "A large wooden desk. There are papers and books covering it";
  items[8] = "skull";
  items[9] = "A skull of an unknown creature. Its jaws are much bigger than ordinary humans'";
	
set_not_out(1);	
  }
