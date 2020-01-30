#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/nalle/area/nheo");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/i2", "east",
"wizards/nalle/area/h2","southeast",
"wizards/nalle/area/h1", "south",
"The weapon storage, main room",
"This is a murky room, with various pieces of armour\n" +
"hung on the walls. This is where all the real weapons \n" +
"are kept. There are beautiful halberds and longswords\n" +
"hanging on the walls. \n", 3)
