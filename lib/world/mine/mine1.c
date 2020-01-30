#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
    if (!present("sign")) {
	move_object("world/objects/sign", this_object());
    }
    if (!items) {
	items = allocate(2); 
	items[0] = "rails";
	items[1] = "The iron rails are rusty and seems like they have not been\n" +
		   "used for a long time. You wonder if the cart still exists";
    }
}

TWO_EXIT("world/mine/path3", "south",
	 "world/mine/mine2", "north",
	 "Mine entrance",
	 "The mining tunnel start here. The wooden props look rotten, like they\n" + 
	 "might give away any moment. Rusty iron rails start here and continue in to\n" + 
	 "the darkness.\n", 2)
