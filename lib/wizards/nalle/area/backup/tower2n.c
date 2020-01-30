#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "portal";
    items[1] = "It looks like you could enter it, and be transported somewhere.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/elraak");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/tower2","south",
"wizards/nalle/area/tower5","portal",
"Elraak's room.",
"You enter a room, quite unlike any you have been in before. The room is \n" +
"very untidy and words of magic have been scribbled here and there. A little \n" +
"mage is standing in the middle of the room casting spells, that make little \n" +
"zapping and popping sounds. \n", 3)
