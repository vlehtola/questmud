#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object mon24,mon25,mon26;

extra_reset()   {
        if(!mon24)      {
        mon24 = clone_object("/wizards/manta/castle/dem2.c");
        move_object(mon24, this_object());
        }
      if(!mon25)        {
        mon25 = clone_object("/wizards/manta/castle/dem5.c");
        move_object(mon25, this_object());
        }
      if(!mon26)        {
        mon26 = clone_object("/wizards/manta/castle/dem3.c");
        move_object(mon26, this_object());
        }
}

ONE_EXIT("/wizards/manta/castle/cas14.c", "south",
            "A dead end",
            "this room seems to be destroyed you can't continue this way\n" +
           "walls have crumbled and blocked all exits.\n", 1)

