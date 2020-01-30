#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object mon18;

extra_reset()   {
        if(!mon18)      {
        mon18 = clone_object("/wizards/manta/castle/dem4.c");
        move_object(mon18, this_object());
        }
      
}

TWO_EXIT("/wizards/manta/castle/cas19.c", "north",
          "/wizards/manta/castle/cas8.c", "south",
            "Western corridor",
            "A corridor leading nothwards.\n" +
            "You hear strange sounds caming from north.\n", 2)
