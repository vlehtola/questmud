#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster24,monster25;

extra_reset() {
        if(!monster24) {
        monster24 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(monster24, this_object());
        }
        if(!monster25) {
        monster25 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(monster25, this_object());
        }
}

ONE_EXIT("/wizards/manta/hill/room13.c", "south",
         "Stables",
         "This used to be stables but now all horses have been eaten.\n", 3)





