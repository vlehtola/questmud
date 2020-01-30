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
        monster = clone_object("/wizards/nalle/area/snail");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/chamron2","west",
"wizards/nalle/area/path2","east",
"A path in the western part of the forest",
"You are on a path leading east, to the tower of Darvox and east to the village of\n" +
"Chamron. The path is pleasant to walk on and the forest surrounding it is beautiful.\n" +
"You see small creatures moving in the forest carrying on with their peaceful lives. \n" +
"You didn't expect the path to be so pleasant. \n", 3)
