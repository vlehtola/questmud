#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster22,monster23;

extra_reset() {
        if(!monster22) {
         monster22 = clone_object("/wizards/manta/castle/dem2.c");
        move_object(monster22, this_object());
        }
        if(!monster22) {
        monster22 = clone_object("/wizards/manta/castle/dem2.c");
        move_object(monster22, this_object());
        }
}

ONE_EXIT("/wizards/manta/hill/room13.c", "north",
         "Blacksmith",
         "Blacksmith, here were all weapons and armours made.\n" +
         "But someone has cleaned this place and took everything.\n" +
         "Only halfeaten corpse of blacksmith remains.\n", 3)





