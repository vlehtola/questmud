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
        monster = clone_object("/wizards/nalle/area/monsters/snail");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/path2","west",
"wizards/nalle/area/grove","east",
"In the middle of the forest.",
"You are in the middle of the forest. Small animals have made nests in\n" +
"the trees, the atmosphere is very comfortable. Small blueberry-bushes\n" +
"cover the ground and you can also spot glimpses of wild strawberry-\n" +
"bushes. The black tower can be seen behind a small distance in the east,\n" +
"but a murky swamp stands between you and the tower.\n", 3)
