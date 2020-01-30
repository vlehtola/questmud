#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object mon10,mon11,mon12,eqmon1;

extra_reset()   {
        if(!mon9)       {
        mon9 = clone_object("/wizards/manta/castle/eqmon1.c");
        move_object(mon9, this_object());
        }
      if(!mon10)        {
        mon10 = clone_object("/wizards/manta/castle/dem6.c");
        move_object(mon10, this_object());
        }
      if(!mon11)        {
        mon11 = clone_object("/wizards/manta/castle/dem3.c");
        move_object(mon11, this_object());
        }
      if(!mon12)        {
        mon12 = clone_object("/wizards/manta/castle/dem3.c");
        move_object(mon12, this_object());
        }

}

ONE_EXIT("/wizards/manta/castle/cas12.c", "east",
            "A tavern backroom",
            "this room seems to be filled with beer barrels and lot's of\n" +
            "demons are having party here they are wery angry too.", 1)

