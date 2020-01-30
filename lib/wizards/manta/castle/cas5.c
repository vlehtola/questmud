#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object mon3;

extra_reset()   {
        if(!mon3)       {
        mon3 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(mon3, this_object());
        }
}

TWO_EXIT("/wizards/manta/castle/cas6.c", "east",
            "/wizards/manta/castle/cas4.c", "west",
            "Southern corridor",
            "A corridor connecting western and eastern part of castle.\n", 2)
