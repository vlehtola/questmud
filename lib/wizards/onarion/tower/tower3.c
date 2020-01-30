#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();

extra_reset() { 
   object ob;
	if (items) { return; }
	set_not_out(1);
	items = allocate(2);        
	items[0] = "books"; 
	items[1] = "You browse through a book and find something interesting:\n"+
		   "The spellwords for Ignite: 'exs fla cre'";
  ob = clone_object("/obj/explore_xp");
  ob->set_name("testi");
  move_object(ob, this_object());
}

long(str) {
    ::long(str);
    if (str == "books") {
	 if (present("spellbook", this_player())) {
	     present("spellbook", this_player())->add_spell("Ignite", "exs fla cre");
	 }
    }
}

THREE_EXIT("wizards/onarion/tower/tower2", "north",
	 "wizards/onarion/tower/tower4", "west",
	 "wizards/onarion/tower/tower5", "east",
	 "Apprentice mage's living room",
	 "This room serves as a living room for the apprentice mages.\n" +
	 "To the east and west lies the rooms of the apprentice mages.\n" + 
	 "The walls are mostly covered with bookshelves full of books.\n", 3)
	 
