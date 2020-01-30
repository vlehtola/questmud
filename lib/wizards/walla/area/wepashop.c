#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/zombie");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/walla/area/ujar1", "east",
         "Ye old Smithy",
         "This is the abandonned smithy's store\n" +
         "The ability to forge steel and to make swords of it was a skill lost\n" +
         "when the last of the Smith's died, Now this store is ruled by someone else\n", 1)
        
