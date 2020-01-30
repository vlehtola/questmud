#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object mon21;

extra_reset()   {
        if(!mon21)      {
        mon21 = clone_object("/wizards/manta/castle/dem4.c");
        move_object(mon21, this_object());
        }
      
}

TWO_EXIT("/wizards/manta/castle/cas17.c", "east",
          "/wizards/manta/castle/cas15.c", "west",
            "A dining hall",
            "Large hall in center of castle used to be dining hall.\n" +
            "But now empty and hollow echoes caming somewhere.\n", 2)
