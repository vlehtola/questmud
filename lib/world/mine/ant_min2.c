#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

object ant;
extra_reset() {    
    if (!ant || !living(ant)) {
	ant = clone_object("world/monsters/ant1.c");
	move_object(ant, this_object());
    }
    set_not_out(1);
}

TWO_EXIT("world/mine/ant_mine", "west",
	 "world/mine/ant_min3", "east",
	 "End of mining tunnel",
	 "The mining tunnel ends here, but a bit smaller and rougher tunnel\n" + 
	 "continues. The walls and ceiling of the smaller tunnel emit a strange\n" + 
	 "greenish dim light.\n", 3)
	 
