#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object mon28,mon29,mon30;
 
extra_reset()   {
        if(!mon28)      {
        mon28 = clone_object("/wizards/manta/castle/dem2.c");
        move_object(mon28, this_object());
        }
      if(!mon29)        {
        mon29 = clone_object("/wizards/manta/castle/dem5.c");
        move_object(mon29, this_object());
        }
      if(!mon30)        {
        mon30 = clone_object("/wizards/manta/castle/dem3.c");
        move_object(mon30, this_object());
        }
}
 
ONE_EXIT("/wizards/manta/castle/cas18.c", "south",
            "A dead end",
            "this room seems to be destroyed you can't continue this way\n" +
            "walls have crumbled and blocked way ahead.", 1)
 
