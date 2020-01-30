#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/trknight");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/i2", "north",
"wizards/nalle/area/i1","northwest",
"wizards/nalle/area/h1", "west",
"The weapon storage.",
"This is a murky room with various pieces of shields and\n" +
"armours hung on the walls. This room seems to have been\n" +
"made to used as a weapons training room, but no real\n" +
"weapons can be seen anywhere around.\n", 3)
