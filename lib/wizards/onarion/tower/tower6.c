#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();

object monster;

extra_reset() {
    set_not_out(1);
    if(!monster) {
	monster = clone_object("wizards/onarion/tower/monsters/guardian");
	move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/onarion/tower/tower7", "up",
	 "wizards/onarion/tower/tower2", "down",
	 "Stairway leading up and down",
	 "This round, stone stairway is leading up and down. There is an iron handrail\n" + 
	 "by the outer side and there are torches attached to the wall.\n", 3)
	 
