#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "cells";
    items[1] = "A long row of cells.";
}

THREE_EXIT("wizards/nalle/area/k2","north",
"wizards/nalle/area/j1","west",
"wizards/nalle/area/j3","east",
"On the bottom floor, south from the staircase.",
"There are prison cells to your east and west. There are no\n" +
"doors on the cells, the occupants are simply chained to the\n" +
"wall by all limbs. The sanitary system does not seem to work\n" +
"in the cells, which causes this smell.\n", 3)

