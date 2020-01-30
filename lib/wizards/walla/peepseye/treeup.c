#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/walla/peepseye/monsters/pepe");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/walla/peepseye/tree1", "down",
        "In a tree",
         "This looks like a hut of some sort. Some guy lives here, and he sits in a rocking\n" +
         "chair in the far corner of the room. The room is very tidy and there is a window\n" +
         "pointing to the sea.\n", 3)


