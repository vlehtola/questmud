#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object mon36,mon37,mon38;
 
extra_reset()   {
        if(!mon36)      {
        mon36 = clone_object("/wizards/manta/castle/eqmon3.c");
        move_object(mon36, this_object());
        }
      if(!mon37)        {
        mon37 = clone_object("/wizards/manta/castle/dem4.c");
        move_object(mon37, this_object());
        }
      if(!mon38)        {
        mon38 = clone_object("/wizards/manta/castle/dem3.c");
        move_object(mon38, this_object());
        }
}
 
ONE_EXIT("/wizards/manta/castle/cas23.c", "west",
            "Wizards room",
            "this room was reserved for wizards who might came to the castle.\n" +
            "Demon forces wizard is currently ysin this room.", 1)
 
