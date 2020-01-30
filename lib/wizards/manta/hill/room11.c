#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster17;

extra_reset() {
        if(!monster17) {
        monster17 = clone_object("/wizards/manta/hill/mon6.c");
        move_object(monster17, this_object());
        }
}

ONE_EXIT("/wizards/manta/hill/room10.c", "south",
         "Guard barracks",
         "These are sleeping quarters for guards now destroyed.\n", 3)

