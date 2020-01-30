#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object mon31,mon32,mon33;
 
extra_reset()   {
        if(!mon31)      {
        mon31 = clone_object("/wizards/manta/castle/eqmon2.c");
        move_object(mon31, this_object());
        }
      if(!mon32)        {
        mon32 = clone_object("/wizards/manta/castle/dem5.c");
        move_object(mon32, this_object());
        }
      if(!mon33)        {
        mon33 = clone_object("/wizards/manta/castle/dem5.c");
        move_object(mon33, this_object());
        }
}
 
ONE_EXIT("/wizards/manta/castle/cas23.c", "east",
            "A throne room",
            "this room was castles throne room but now deserted.\n" +
            "Leader of demon forces is currently usin this room.", 1)
 
