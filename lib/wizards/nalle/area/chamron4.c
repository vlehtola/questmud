#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "gate";
    items[1] = "The gate is no longer either bolted or locked";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/knight2");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/drawbridge","north",
"wizards/nalle/area/chamron3","south",
"The path to the Dequan Fortification.",
"This is the path to the Dequan fortification. Almost a year has passed\n" +
"after the barbarian attack and the gate leading to the fortress is once\n" +
"again open. You have heard that the Knights have assembled to discuss\n" +
"about important matters. There is a large drawbridge to the north. The\n" +
"drawbridge is now lowered.\n", 3)
