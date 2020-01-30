inherit "room/room";


object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/summoner");
    move_object(monster, this_object());
  }

add_exit("west","/wizards/veron/areat/golem/room7.c");
add_exit("ladder","/wizards/veron/areat/golem/room11.c");

  short_desc = "Small workroom";

  long_desc = "This place looks like a workroom. There are papers everywhere.\n"+
		  "Large bookshelves full of books conceal the walls and windows.\n"+
		  "A large desk is in the northwestern corner. Small candles are\n"+
		  "burning on the desk, giving dim light to the room. A deck of \n"+
		  "cards is on the table. A ladder leads to a hatch in the ceiling\n"+
		  "of this room.\n";

		 
  items = allocate(12);
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
  items[8] = "cards"; 
  items[9] = "A deck of colorful cards. There's a text in the back of the cards reading\n"+
		 "'Magic:the gathering'. You put the cards quickly back on the desk. They must\n"+
 		 "be used in some kind of dark rituals";
  items[10] = "deck"; 
  items[11] = "A deck of colorful cards. There's a text in the back of the cards reading\n"+
		 "'Magic:the gathering'. You put the cards quickly back on the desk. They must\n"+
 		 "be used in some kind of dark rituals";

set_not_out(1);
		
  }
