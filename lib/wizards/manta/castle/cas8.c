#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object mon6,mon7;

extra_reset()   {
        if(!mon6)       {
        mon6 = clone_object("/wizards/manta/castle/dem3.c");
        move_object(mon6, this_object());
        }
      if(!mon7) {
        mon7 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(mon7, this_object());
        }
}

THREE_EXIT("/wizards/manta/castle/cas14.c", "north",
          "/wizards/manta/castle/cas9.c", "east",
            "/wizards/manta/castle/cas2.c", "south",
            "Western corridor",
            "A corridor leading nothwards.\n", 2)
