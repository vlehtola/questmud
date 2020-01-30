#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/nalle/area/knight2");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/a3", "north",
         "wizards/nalle/area/chamron4", "south",
         "The drawbridge",
         "You are now on a sturdy drawbridge. It is has been built\n" +
         "to prevent any enemies getting into the fortification.\n" +
         "To the north you see the large fortifications once built \n" +
         "by the Dequan Knights. \n", 3)
