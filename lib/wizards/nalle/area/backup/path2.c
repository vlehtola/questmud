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

FOUR_EXIT("wizards/nalle/area/path","west",
"wizards/nalle/area/pathe","east",
"wizards/nalle/area/paths","south",
"wizards/nalle/area/pathn","north",
"A path in the middle of the forest",
"You are on a path leading east, to the tower of Darvox and east to the village of\n" +
"Chamron. The path is pleasant to walk on and the forest surrounding it is beautiful.\n" +
"You may also venture deeper into the forest, to the noth or to the south. You hear \n" +
"noises of animals from both directions. \n", 3)

