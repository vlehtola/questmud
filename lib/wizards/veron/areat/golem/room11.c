inherit "room/room";


object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/igolem");
    move_object(monster, this_object());
  }

add_exit("down","/wizards/veron/areat/golem/room10.c");

  short_desc = "Messy room";

  long_desc = "A small room with an incredible mess. The floor is completely\n"+
		  "covered in papers and books. A  bookshelf full of books can also\n"+
		  "been found here. A small bed is located in the southeastern corner.\n"+
		  "It seems that the summoner sleeps here. A small hatch in the floor\n"+
		  "leads downstairs.\n";
                         
		 
  items = allocate(8);
  items[0] = "papers";
  items[1] = "Papers with some notes in them. The hand-writing is awful,\n"+ 
             "you can't read it";
  items[2] = "books";
  items[3] = "Some magic books with pentagrams in their covers. You don't\n"+
             "understand the text in them";
  items[4] = "hatch";
  items[5] = "A wooden hatch. It's not locked";
  items[6] = "bookshelf";
  items[7] = "An oaken bookshelf stuffed with books";
set_not_out(1);		
  }
