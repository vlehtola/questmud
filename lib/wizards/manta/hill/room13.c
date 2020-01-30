#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster19,monster20,monster21;

extra_reset() {
        if(!monster19) {
        monster19 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(monster19, this_object());
        }
        if(!monster20) {
        monster20 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(monster20, this_object());
        }
        if(!monster21) {
         monster21 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(monster21, this_object());
        }
}

THREE_EXIT("/wizards/manta/hill/room15.c", "north",
           "/wizards/manta/hill/room14.c", "south",
           "/wizards/manta/hill/room6.c", "west",
           "A small path",
           "This is small path leading to fortress stables.\n", 3)



