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
        monster = clone_object("/wizards/nalle/area/monsters/hedgehog");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/path2","north",
"In the middle of the forest",
"You are in the middle of the green forest. Small animals have made\n" +
"their nests in the trees. The atmosphere here feels very comfortable.\n" +
"Small blueberry-bushes cover the ground, but you can also spot\n" +
"glimpses of wild strawberry-bushes among them. The forest thickens\n" +
"southwards and you cannot continue that way.\n", 3)
