#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "gate";
    items[1] = "The gate is no longer bolted or locked.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/knight2");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/drawbridge","north",
"wizards/nalle/area/chamron3","south",
"The path to the Dequan Fortification",
"This is the path to the Dequan fortification. The gate leading to it\n" +
"is once again open. You have heard that the Knights have assembled \n" +
"to discuss important matters. There is a large drawbridge to the north \n" +
"which is now lowered. \n", 3)
