#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(1);

TWO_EXIT(  "/wizards/celtron/cave/cave4", "north",
	   "/wizards/celtron/cave/cave2", "northwest",
	   "Dim tunnel",
	   "No light sources are nearby, making this place really dim.\n" +
	   "Walls, ceiling and floor are all pure stone.\n" +
	   "Some water drops from ceiling making soft sounds.\n", 1)