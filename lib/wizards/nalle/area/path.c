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

TWO_EXIT("wizards/nalle/area/chamron2","west",
"wizards/nalle/area/path2","east",
"A path in the western part of the forest",
"You are on a path leading east and west. In east can be seen the\n" +
"black tower of Darvox and in west the village of Chamron. The path\n" +
"is pleasant to walk on and the surrounding forest is really a\n" +
"beautiful sight. You see some small creatures moving deeper in the\n" +
"forest, carrying on with their peaceful everyday life. You did not\n" +
"expect the path to be so pleasant. \n", 3)
