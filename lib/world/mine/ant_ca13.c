#include "room.h"
object ant, ant2;
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

TWO_EXIT("world/mine/ant_ca12", "south",
	 "world/mine/ant_ca11", "east",        
	 "North-west corner of ant cave",
	 "You are walking in a huge ant nest.\n" +
	 "The ceiling looks very solid and must have been done by ants.\n" + 
	 "You can see, because there is some strange light\n" + 
	 "coming from the rocks.\n", 3)
	 
