#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster6,monster7,monster8;

extra_reset() {
        if(!monster6) {
        monster6 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(monster6, this_object());
        }
        if(!monster7) {
        monster7 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(monster7, this_object());
        }
        if(!monster8) {
        monster8 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(monster8, this_object());
        }
}

FOUR_EXIT("/wizards/manta/hill/room9.c", "north",
           "/wizards/manta/hill/room4.c", "east",
           "/wizards/manta/hill/room8.c", "south",
           "/wizards/manta/hill/room12.c", "west",
             "A small path",
           "This is small path leading to fortress cooking facilities.\n", 3)


