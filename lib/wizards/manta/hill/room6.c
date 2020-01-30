#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster9,monster10,monster11;

extra_reset() {
        if(!monster9) {
        monster9 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(monster9, this_object());
        }
        if(!monster10) {
        monster10 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(monster10, this_object());
        }
        if(!monster11) {
        monster11 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(monster11, this_object());
        }
}

THREE_EXIT("/wizards/manta/hill/room10.c", "north",
           "/wizards/manta/hill/room13.c", "east",
           "/wizards/manta/hill/room4.c", "west",
           "A small path",
           "This is small path leading to fortress guard housing.\n", 3)



