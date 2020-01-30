#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object mon2;

extra_reset()   {
        if(!mon2)       {
        mon2 = clone_object("/wizards/manta/castle/dem3.c");
        move_object(mon2, this_object());
        }
}

FOUR_EXIT("/wizards/manta/castle/cas10.c", "north",
            "/wizards/manta/castle/cas5.c", "east",
            "/wizards/manta/castle/cas1.c", "south",
          "/wizards/manta/castle/cas3.c", "west",
            "Southern corridor",
            "A corridor connecting western and eastern part of castle.\n" +
            "To south is castle entrance and long corridor runs to north.\n", 2)
