#include "room.h"
object ant, ant2;
extra_reset() {    
    if (!ant || !living(ant)) {
	ant = clone_object("world/monsters/ant2.c");
	move_object(ant, this_object());
    }
    if (!ant2 || !living(ant2)) {
	ant2 = clone_object("world/monsters/ant2.c");
	move_object(ant2, this_object());
    }
    set_not_out(1);
}

#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();

THREE_EXIT("world/mine/ant_ca13", "north",
	 "world/mine/ant_ca10", "east",        
	 "world/mine/ant_cav4", "south",        
	 "Ant cave",
	 "You are walking in a huge ant nest.\n" +
	 "The ceiling looks very solid and must have been done by ants.\n" + 
	 "You can see, because there is some strange light\n" + 
	 "coming from the rocks.\n", 3)
	 
