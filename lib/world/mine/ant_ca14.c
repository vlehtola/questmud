#include "room.h"
object ant, ant2;
extra_reset() {    
    if (!ant || !living(ant)) {
	    ant = clone_object("world/monsters/ant4.c");
	    move_object(ant, this_object());
    }
    if (!ant2 || !living(ant2)) {
	    ant2 = clone_object("world/monsters/ant4.c");
	    move_object(ant2, this_object());
    }
    set_not_out(1);
}

#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();

TWO_EXIT("world/mine/ant_cav9", "south",
	 "world/mine/antqueen", "east",        
	 "Entrance to the queens nest",
	 "You are in an entrance to the ant queens nest. It lies to the east.\n" +
	 "A terrible smell comes from there and you can hear something\n" +
	 "slimy and large moving in it.\n", 3)

