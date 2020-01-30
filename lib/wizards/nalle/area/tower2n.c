#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "portal";
    items[1] = "Looks like you could get transported somewhere if you would enter the portal";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/elraak");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/tower2","south",
"wizards/nalle/area/tower5","portal",
"Elraak's room",
"You enter a room, quite unlike any you have been in before. The room\n" +
"is very untidy and words of magic have been scribbled here and there.\n" +
"Few small robes are hanging on the western wall, maybe the resident\n" +
"of this room is also small of size. Here and there on the walls there\n" +
"seems to be some burnt areas, maybe caused by mistargeted spells.\n", 3)
