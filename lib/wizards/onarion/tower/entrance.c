#include "room.h"

object guard1,guard2;

extra_reset() {    
    if (!guard1 || !living(guard1)) {
	guard1 = clone_object("wizards/onarion/tower/monsters/guard.c");
	move_object(guard1, this_object());
    }
    if (!guard2 || !living(guard2)) {
	guard2 = clone_object("wizards/onarion/tower/monsters/guard.c");
	move_object(guard2, this_object());
    }
}

#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();

FOUR_EXIT("wizards/onarion/tower/tower1", "enter",
	 "out: 50 30", "west",
	 "out: 50 30", "north",
	 "out: 50 30", "south",
	 "Tower entrance",
	 "You are standing in front of a huge stone tower that rises high\n" +
	 "above your head. There is a gate leading in.\n", 3)
	 
