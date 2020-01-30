#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "inn";
    items[1] = "The inn looks nice and cosy";
}

FOUR_EXIT("wizards/nalle/area/inn", "west",
         "wizards/nalle/area/chamron3", "north",
         "wizards/nalle/area/entrance", "south",
         "wizards/nalle/area/path1", "east",
         "Southern part of the City of Chamron",
         "You are presently in a Southern part of the City of Chamron.\n" +
         "There are many people of various races spending their  \n" +
         "time in this crowded part of the town. To the west seems to\n" +
         "be an inn of some kind and to the south the south gate. \n" + 
         "A path to your east seems to lead to a massive black tower in the\n" + 
         "eastern side of the city .\n", 1)

