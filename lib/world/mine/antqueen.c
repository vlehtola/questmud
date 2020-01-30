#include "room.h"
object ant;
int cloned;

extra_reset() {
    if (!cloned) {
	ant = clone_object("world/monsters/antqueen.c");
	move_object(ant, this_object());
	cloned = 1;
    }
    set_not_out(1);
}

#undef EXTRA_RESET
#define EXTRA_RESET\
	extra_reset();

ONE_EXIT("world/mine/ant_ca14", "west",
	 "Ant nest",
	 "The ceiling looks very solid and must have been done by ants.\n" + 
	 "It stinks like rotten plants and flesh. The walls are covered with\n" + 
	 "something slimy and muddy. There are ant eggs all over the place.\n" + 
	 "You can see, because the rocks emit some strange light.\n", 2)
	 
