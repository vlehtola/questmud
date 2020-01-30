#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/esquire");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/i1", "north",
"wizards/nalle/area/h2","east",         
"wizards/nalle/area/g1", "south",
"The weapon storage.",
"This is a murky room with various pieces of armours hung\n" +
"on the walls. In addition to the armours there are also\n" +
"some shields, but all the actual weapons seem to be missing.\n", 3)

