#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "trees";
    items[1] = "The trees consist of oaks and other warm climate trees";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/hedgehog");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/path2","north",
"In the middle of the forest",
"You are in the middle of the forest. Small animals have made nests in the trees\n" +
"atmosphere is very comfortable. Small blueberry bushes cover the ground and.\n" +
"you can also spot glimpses of wild strawberry bushes too. The forest gets \n" +
"thicker to the other directions except for the one you came from. \n", 3)
