#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/nalle/area/trknight");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/i2", "north",
"wizards/nalle/area/i1","northwest",
"wizards/nalle/area/h1", "west",
"The weapon storage",
"This is a murky room, with various pieces of armour\n" +
"hung on the walls. This room seems to have been made\n" +
"to be used as a room for the training weapons, but you\n" +
"still cant find any of the good stuff. \n", 3)
