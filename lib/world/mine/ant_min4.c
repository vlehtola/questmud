#include "room.h"
object ant, ant2;
extra_reset() {    
    if (!ant || !living(ant)) {
       ant = clone_object("world/monsters/ant1.c");
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

ONE_EXIT("world/mine/ant_min3", "west",
	 "Dead end of strange small tunnel",
	 "The strange tunnel ends here, and you come to a dead end.\n" + 
	 "You can see, because there is some strange light" + 
	 "coming from the rocks.\n", 3)
	 
