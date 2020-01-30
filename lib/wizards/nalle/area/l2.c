#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "cells";
    items[1] = "A long row of uncomfortable-looking, stony prison cells";
set_not_out();
}

FOUR_EXIT("wizards/nalle/area/m2","north",
"wizards/nalle/area/l1","west",
"wizards/nalle/area/l3","east",
"wizards/nalle/area/k2","south",
"On the bottom floor, south from the staircase.",
"There are prison cells to your east and west. There are no\n" +
"doors on the cells, the occupants are simply chained to the\n" +
"wall from all of their limbs. The sanitary system does not\n" +
"seem to work in the cells, which causes the horrible smell.\n", 3)
