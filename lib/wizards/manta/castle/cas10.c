#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object mon9;

extra_reset()   {
        if(!mon9)       {
        mon9 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(mon9, this_object());
        }
}

TWO_EXIT("/wizards/manta/castle/cas15.c", "north",
          "/wizards/manta/castle/cas4.c", "south",
            "A corridor",
            "This is corridor leading to north part of castle.\n", 2)
