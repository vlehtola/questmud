#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object mon8;

extra_reset()   {
        if(!mon8)       {
        mon8 = clone_object("/wizards/manta/castle/dem4.c");
        move_object(mon8, this_object());
        }
}

TWO_EXIT("/wizards/manta/castle/cas3.c", "south",
          "/wizards/manta/castle/cas8.c", "west",
            "Weapon room",
            "This is weapon room where people caming to castle left their\n" +
            "weapons during their stay in castle.\n", 2)
