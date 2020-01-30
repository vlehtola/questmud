#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
    if (items) { return 0; }
    items = allocate(2); 
    items[0] = "rails";
    items[1] = "The iron rails are rusty and seems like they have not been\n" +
	       "used for a long time. You wonder if the cart still exists";
    set_not_out(1);
}

THREE_EXIT("world/mine/mine2", "up",
	   "world/mine/rat_mine", "north",
	   "world/mine/ant_mine", "east",
	   "Old mining tunnel",
	   "The mining tunnel branches here to the east and north. The main tunnel\n" + 
	   "that continues to the north stinks like rats and is completely dark.\n" +
	   "The tunnel leading east is smaller, but some there is a dim light coming\n" + 
	   "from the depths of the darkness. From up, you can smell a fresh air.\n" + 
	   "Rusty iron rails continue north, deeper in to the darkness.\n", 3)
	 
