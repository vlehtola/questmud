inherit "room/room";


object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/igolem");
    move_object(monster, this_object());
  }

add_exit("down","/wizards/veron/areat/golem/room8.c");

  short_desc = "Messy room";

  long_desc = "A small room with an incredible mess. The floor is completely \n"+
		  "covered with papers and books. A bookshelf full of books can also\n"+
		  "be found here. An uncomfortable-looking wooden bed lies in the\n"+
		  "corner. It seems that this is the summoner's bedroom. A small \n"+
		  "table next to the bed has a book on it.\n";
          	 
  items = allocate(10);
  items[0] = "papers";
  items[1] = "Papers with some notes in them. The hand-writing is awful,\n"+ 
             "you can't read it.";
  items[2] = "books";
  items[3] = "Some magic books with pentagrams in their covers. You don't\n"+
             "understand the text in them.";
  items[4] = "hatch";
  items[5] = "A wooden hatch. It's not locked.";
  items[6] = "bookshelf";
  items[7] = "An oaken bookshelf stuffed with books.";
  items[8] = "book";
  items[9] = "You read the book's label : 'J.R.R Tolkien, Lord of the rings'";
set_not_out(1);		
  }
