#include "room.h"
object ant;
extra_reset() {    
    if (!ant || !living(ant)) {
	ant = clone_object("world/monsters/ant3.c");
	move_object(ant, this_object());
    }
    set_not_out(1);
}

#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();

TWO_EXIT("world/mine/ant_cav2", "west",
	 "world/mine/ant_ca5", "north",        
	 "Ant cave",
	 "You are walking in a huge ant nest.\n" +
	 "The ceiling looks very solid and must have been done by ants.\n" + 
	 "You can see, because there is some strange light\n" + 
	 "coming from the rocks.\n", 3)
	 
