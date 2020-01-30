#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

object rat, rat2;

extra_reset() {
    if (!rat) {
	if (random(2) == 1) {
	    rat = clone_object("/world/mine/monsters/rat");
	}
	if (random(2) == 1) {
	    rat = clone_object("/world/mine/monsters/smallrat");
	}
	if (!rat) { rat = clone_object("/world/mine/monsters/big_rat"); }
	move_object(rat, this_object());
    }
    if (!rat2) {
	if (random(2) == 1) {
	    rat2 = clone_object("/world/mine/monsters/smallrat");
	}
	if (random(3) == 1) {
	    rat2 = clone_object("/world/mine/monsters/rat");
	}
	if (rat2) {
	   move_object(rat2, this_object());
	}
    }
    if (items) { return 0; }
    items = allocate(2); 
    items[0] = "rails";
    items[1] = "The iron rails are rusty and seems like they have not been\n" +
	       "used for a long time. You wonder if the cart still exists";
    set_not_out(1);
}

TWO_EXIT("world/mine/rat_mine", "south",
	   "world/mine/rat_min3", "west",
	 /*  "world/mine/mine4", "north",  */
	   "Branch in the old mining tunnel",
	   "The mining tunnel branches to the east and north here. It stinks\n" + 
	   "like rats here. To the south however you can smell fresher air.\n" +
	   "Rusty iron rails lead north, deeper in to the darkness.\n", 1)
	 
