#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "furniture";
    items[1] = "The furniture is simple, and made of plain wood.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/tarboy1");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/tie2","south",
"A house on the Tartan avenue",
"This is a very modest house, like most others on the Tartan avenue.\n" +
"There are a few pieces of obligatory furniture, which are made of plain \n" +
"wood. The room seems a bit messy but not unclean. \n", 3)

