#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object mon22,mon23;

extra_reset()   {
        if(!mon22)      {
        mon22 = clone_object("/wizards/manta/castle/dem4.c");
        move_object(mon22, this_object());
        }
      if(!mon23)        {
        mon23 = clone_object("/wizards/manta/castle/dem2.c");
        move_object(mon23, this_object());
        }
}

THREE_EXIT("/wizards/manta/castle/cas18.c", "east",
          "/wizards/manta/castle/cas12.c", "south",
            "/wizards/manta/castle/cas16.c", "west",
            "A castle kitchen",
            "A large and cozy kitchen next to dining hall.\n", 2)
