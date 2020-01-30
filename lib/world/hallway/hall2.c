#include "room.h"
object monsu;

extra_reset(arg) {    
    if(arg) { return; }
    set_not_out(1);
    set_blocker("guard", "north");
    if (!monsu || !living(monsu)) {
	monsu = clone_object("/world/hallway/orc");
        move_object(monsu, this_object());
    }
}

#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();


TWO_EXIT("world/hallway/hall1", "south",
	 "world/hallway/hall3", "north",
	 "Long hallway",
	 "A long hallway, lighted by torches hanging on the both side walls\n" +
	 "goes north, inside this mountain.\n", 1)
