#include "room.h"
object ant, ant2, ant3;
extra_reset() {    
    if (!ant || !living(ant)) {
	ant = clone_object("world/monsters/ant2.c");
	move_object(ant, this_object());
    }
    if (!ant2 || !living(ant2)) {
	ant2 = clone_object("world/monsters/ant2.c");
	move_object(ant2, this_object());
    }
    if (!ant3 || !living(ant3)) {
	ant3 = clone_object("world/monsters/ant3.c");
	move_object(ant3, this_object());
    }
    set_not_out(1);
}

#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();

FOUR_EXIT("world/mine/ant_ca12", "west",
	 "world/mine/ant_ca11", "north",        
	 "world/mine/ant_cav7", "south",        
	 "world/mine/ant_cav8", "east",        
	 "Center of ant cave",
	 "You are in the center of a huge ant nest.\n" +
	 "The ceiling looks very solid and must have been done by ants.\n" + 
	 "You can see, because there is some strange light\n" + 
	 "coming from the rocks.\n", 3)
	 
