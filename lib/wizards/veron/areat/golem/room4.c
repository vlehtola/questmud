inherit "room/room";


object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/summoner");
    move_object(monster, this_object());
  }

add_exit("east","/wizards/veron/areat/golem/room3.c");
add_exit("hatch","/wizards/veron/areat/golem/room5.c");

  short_desc = "Small workroom";

  long_desc = "This place looks like a workroom. There are papers everywhere. \n"+
		  "Large bookshelves full of books conceal the walls and windows.\n"+
		  "There's a desk in the middle of the room. Small candles are \n"+
		  "burning on the desk, giving dim light to the room. There's \n"+
		  "also a plate with some food on it on the desk. A small hatch\n"+
		  "in the floor can be noticed in the middle of this room.\n";
             
		 
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
  items[8] = "plate";
  items[9] = "A plate with some food on it. Maybe todays meal";
	
set_not_out(1);	
  }
