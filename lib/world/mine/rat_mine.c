#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

object rat;

extra_reset() {
    if (!rat) {
	if (random(2) == 1) {
	    rat = clone_object("/world/mine/monsters/rat");
	}
	if (!rat) { rat = clone_object("/world/mine/monsters/smallrat"); }
	move_object(rat, this_object());
    }
    if (items) { return 0; }
    items = allocate(2); 
    items[0] = "rails";
    items[1] = "The iron rails are rusty and seems like they have not been\n" +
	       "used for a long time. You wonder if the cart still exists";
    set_not_out(1);
}

TWO_EXIT("world/mine/mine3", "south",
	   "world/mine/rat_min2", "north",
	   "Old mining tunnel",
	   "The mining tunnel continues to the north and south. It stinks\n" + 
	   "like rats here. To the south however you can smell fresher air.\n" +
	   "Rusty iron rails lead north, deeper in to the darkness.\n", 1)
	 
