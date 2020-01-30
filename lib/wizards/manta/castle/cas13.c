#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object mon16,mon17;

extra_reset()   {
        if(!mon16)      {
        mon16 = clone_object("/wizards/manta/castle/dem3.c");
        move_object(mon16, this_object());
        }
      if(!mon17)        {
        mon17 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(mon17, this_object());
        }
}

THREE_EXIT("/wizards/manta/castle/cas18.c", "north",
          "/wizards/manta/castle/cas12.c", "west",
            "/wizards/manta/castle/cas7.c", "south",
            "Eastern corridor",
            "A corridor leading nothwards.\n", 2)
