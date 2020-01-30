#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "staircase";
    items[1] = "It leads up and down.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/blockknight");
        move_object(monster, this_object());
    }
}

FIVE_EXIT("wizards/nalle/area/n2","down",
"wizards/nalle/area/i5u","up",
"wizards/nalle/area/i4","west",
"wizards/nalle/area/h4","southwest",
"wizards/nalle/area/h5","south",
"Northeastern corner of the fortress, at the staircase.",
"This is the northern corner of the fortress. \n" +
"There is a large staircase leading up and down\n" +
"in one corner. The way up seems much cleaner\n" +
"and you can hear strange moans from downstairs.\n", 3)

