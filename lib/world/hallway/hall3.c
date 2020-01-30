#include "room.h"

object monsu;

extra_reset() {    
    set_blocker("guard", "south");
    set_not_out(1);
    if (!monsu || !living(monsu)) {
        monsu = clone_object("/world/hallway/orc");
	move_object(monsu, this_object());
    }
}

#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();

THREE_EXIT("/world/hallway/hall2", "south",
	   "/world/hallway/hall4", "north",
	   "/world/hallway/cave", "east",
	   "Long hallway",
	   "A long hallway, lighted by torches hanging on the both side walls\n" +
	   "goes north, inside this mountain.\n", 2)
