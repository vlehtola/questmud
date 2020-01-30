#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object mon4,mon5;

extra_reset()   {
        if(!mon4)       {
        mon4 = clone_object("/wizards/manta/castle/dem3.c");
        move_object(mon4, this_object());
        }
      if(!mon5) {
        mon5 = clone_object("/wizards/manta/castle/dem4.c");
        move_object(mon5, this_object());
        }
}

THREE_EXIT("/wizards/manta/castle/cas12.c", "north",
          "/wizards/manta/castle/cas7.c", "east",
            "/wizards/manta/castle/cas5.c", "west",
            "Southern corridor",
            "A corridor connecting western and eastern part of castle.\n", 2)
