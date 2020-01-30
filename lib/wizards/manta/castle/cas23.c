#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object mon34,mon35;
 
extra_reset()   {
        if(!mon34)      {
        mon34 = clone_object("/wizards/manta/castle/dem4.c");
        move_object(mon34, this_object());
        }
      if(!mon35)        {
        mon35 = clone_object("/wizards/manta/castle/dem3.c");
        move_object(mon35, this_object());
        }
}
 
THREE_EXIT("/wizards/manta/castle/cas24.c", "east",
          "/wizards/manta/castle/cas20.c", "south",
            "/wizards/manta/castle/cas22.c", "west",
            "A guard post",
            "At this spot guards checked every person entering throne room for\n" +
            "illegal weapons. And now demons are here killing everyone.\n", 2)
