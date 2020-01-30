#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/nalle/area/esquire");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/i1", "north",
"wizards/nalle/area/h2","east",         
"wizards/nalle/area/g1", "south",
"The weapon storage",
"This is a murky room, with various pieces of armour\n" +
"hung on the walls. In addition to the armour there are\n" +
"also some shields, but all the real weapons seem to be\n" +
"missing. \n", 3)

