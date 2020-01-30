#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object mon27;
 
extra_reset()   {
        if(!mon27)      {
        mon27 = clone_object("/wizards/manta/castle/dem3.c");
        move_object(mon27, this_object());
        }
      
}
 
TWO_EXIT("/wizards/manta/castle/cas23.c", "north",
          "/wizards/manta/castle/cas15.c", "south",
            "A corridor",
            "A corridor leading nothwards.\n" +
            "This is wery centre of castle and evil creatures are everywhere.\n", 2)
