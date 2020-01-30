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

TWO_EXIT("world/mine/mine1", "south",
	 "world/mine/mine3", "down",
	 "Old mining tunnel",
	 "You are in a old, deserted mining tunnel. There are rusty iron rails going\n" +
	 "down to the darkness. The mining tunnel continues down from here, but to the\n" + 
	 "south lies the exit from these mines.\n", 2)
	 
	 




