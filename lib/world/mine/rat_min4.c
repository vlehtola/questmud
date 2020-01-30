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
    set_not_out(1);
}

TWO_EXIT("world/mine/rat_min3", "east",
	 "world/mine/rat_min5", "west",
	   "Old mining tunnel",
	   "The mining tunnel continues east and west. It stinks\n" + 
	   "like rats here. To the east however you can smell fresher air.\n", 1)
