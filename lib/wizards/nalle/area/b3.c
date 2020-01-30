#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "fortess";
    items[1] = "The knights' fortress.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/knight2");
        move_object(monster, this_object());
    }
}

FOUR_EXIT("wizards/nalle/area/c3","north",
"wizards/nalle/area/b2","west",
"wizards/nalle/area/b4","east",
"wizards/nalle/area/a3","south",
"A path leading to the fortress, in the middle of the training-grounds.",
"An old cobblestone road, leading north to the Dequan knights' fortress.\n" +
"To the west and to the east you see knight training their skills of \n" +
"honorable fighting. \n", 3)
