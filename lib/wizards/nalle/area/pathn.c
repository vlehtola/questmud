#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "trees";
    items[1] = "The trees consist of oaks and other trees common to the warm climate";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/hedgehog");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/path2","south",
"wizards/nalle/area/jroom1","northeast",
"In the middle of the forest",
"You are in the middle of the forest. Small animals have made their\n" +
"nests in the trees. The atmosphere here feels very comfortable. Small\n" +
"blueberry-bushes cover the ground, but you can also spot glimpses of\n" +
"wild strawberry-bushes among them. A small path leads to northeast and\n" +
"south, where it seems to get a bit wider.\n", 3)
