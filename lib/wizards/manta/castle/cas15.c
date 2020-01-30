#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object mon19,mon20;

extra_reset()   {
        if(!mon19)      {
        mon19 = clone_object("/wizards/manta/castle/dem4.c");
        move_object(mon19, this_object());
        }
      if(!mon20)        {
        mon20 = clone_object("/wizards/manta/castle/dem1.c");
        move_object(mon20, this_object());
        }
}

THREE_EXIT("/wizards/manta/castle/cas20.c", "north",
          "/wizards/manta/castle/cas16.c", "east",
            "/wizards/manta/castle/cas10.c", "south",
            "A corridor",
            "A corridor leading northen part of castle.\n", 2)
