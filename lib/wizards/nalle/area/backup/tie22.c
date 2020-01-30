#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "sewer";
    items[1] = "The lid seems to be missing from the sewer entry.";
}

FOUR_EXIT("wizards/nalle/area/tie2","west",
"wizards/nalle/area/sewer1","down",
"wizards/nalle/area/tarhouse4","north",
"wizards/nalle/area/bmagic","south",
"Further on the Tartan Avenue",
"You have arrived to the poorest part of Chamron.\n" +
"This part of the Tartan Avenue is the worst. The stench of the\n" +
"sewers is unbearable, and the residence to your north seems\n" +
"quite unliveable. An entry to the sewer system that seems frequently\n" +
"used leads down, and there is some sort of a shop to your south. \n" +
"Many suspicious looking characters seem to have found their way here.\n", 4)

