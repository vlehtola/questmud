#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "sewer";
    items[1] = "The sewer pipes look crappy, and a cruel stench is rising from them";
}

FOUR_EXIT("wizards/nalle/area/chamron3","west",
"wizards/nalle/area/tie22","east",
"wizards/nalle/area/tarhouse2","north",
"wizards/nalle/area/tarhouse3","south",
"The Tartan Avenue",
"You are in the poorer part of Chamron, on the Tartan Avenue.\n" +
"There are less people here, mostly only poor-looking workers,\n" +
"who are on their way to work or to their modest homes. The\n" +
"avenue continues to the east, and there are large houses to\n" +
"your north and south. The sewer-system in Chamron seems to\n" +
"be old fashioned and not completely functional.\n", 4)

