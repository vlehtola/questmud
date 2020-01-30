#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "dartboard";
    items[1] = "A dartboard with a picture of Darvox. Most of the darts have missed though.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/commander");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/i5","down",
"The Commander's room.",
"This is the commander's room. There are papers\n" +
"concerning tactics and such rubbish everywhere.\n" +
"There are also many pictures of the tower of high\n" +
"sorcery, and a dartboard with Darvox' picture on it.\n", 3)

