#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();

object monster;

extra_reset() {
    set_not_out(1);
    if(!monster) {
	monster = clone_object("wizards/onarion/tower/monsters/greenadv");
	move_object(monster, this_object());
    }
}

FOUR_EXIT("wizards/onarion/tower/tower9", "up",
	 "wizards/onarion/tower/tower7", "north",
	 "world/mage/magicians", "west",
	 "world/mage/navigator", "east",
	 "Corridor",
	 "You are in an arched corridor. It continues to the north.\n" + 
	 "Stone stairs lead up. There are torches attached to the wall.\n", 3)
	 
