#include "room.h"

extra_reset() {    
    set_not_out(1);
}

#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();

TWO_EXIT("world/hallway/hall4", "southwest",
	 "out: 214 68", "north",
	 "Long hallway",
	 "There is an exit to some kind of valley in east.\n"+
	 "A long hallway, lighted by torches hanging on the both side walls\n" +
	 "goes north, inside this mountain.\n", 1)
