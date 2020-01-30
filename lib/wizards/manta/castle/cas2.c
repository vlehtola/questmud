#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object mon1;

extra_reset()   {
        if(!mon1)       {
        mon1 = clone_object("/wizards/manta/castle/dem3.c");
        move_object(mon1, this_object());
        }
}

TWO_EXIT("/wizards/manta/castle/cas8.c", "north",
           "/wizards/manta/castle/cas3.c", "east",
           "Turning point",
           "At this spot southern and western corridor meet.\n" +
           "You can hear screams echoing from north.\n" +
           "To east seems to be endless corridor.\n", 2)
