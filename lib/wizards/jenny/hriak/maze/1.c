#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(1);

TWO_EXIT(  "/wizards/celtron/maze/entrance", "west",
   	   "/wizards/celtron/maze/2", "east",
	   "Inside the cave",
	   "There is light coming from the west.\n" +
	   "Cave's walls, ceiling and floor are all rough stone.\n" +
	   "The light fades into the darkness of the cave in east.\n", 2)
