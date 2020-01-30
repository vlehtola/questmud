#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster18;

extra_reset() {
        if(!monster18) {
        monster18 = clone_object("/wizards/manta/castle/dem2.c");
        move_object(monster18, this_object());
        }
}

ONE_EXIT("/wizards/manta/hill/room5.c", "east",
         "Food storage",
         "This was once food storage but now deserted and demolished.\n" +
         "You can still see traces of some foul creatures in floor.\n" +
         "Faint bloodstains prove there were some avalonians when creatures came.\n", 3)






