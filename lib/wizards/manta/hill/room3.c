#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster2,monster3;

extra_reset() {
        if(!monster2) {
monster2 = clone_object("wizards/manta/castle/dem1.c");
        move_object(monster2, this_object());
        }
        if (!monster3) {
        monster3 = clone_object("wizards/manta/castle/dem1.c");
        move_object(monster3, this_object());
        }
}

TWO_EXIT("/wizards/manta/hill/room4.c", "north",
           "/wizards/manta/hill/room2.c", "south",
           "Gatekeepers post",
           "At this spot gatekeeper used to stand watching people caming to fortress.\n" +
           "You still can fell fear from people who tried to smuggle goods inside\n" +
           "in front of gatekeepers keen eyes.\n", 3)

