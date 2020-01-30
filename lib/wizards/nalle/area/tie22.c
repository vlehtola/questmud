#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "sewer";
    items[1] = "The lid seems to be missing from the sewer entry, and the black\n" +
               "hole is gaping empty in the side of the avenue";
}

FOUR_EXIT("wizards/nalle/area/tie2","west",
"wizards/nalle/area/sewer1","down",
"wizards/nalle/area/tarhouse4","north",
"wizards/nalle/area/bmagic","south",
"Further on the Tartan Avenue",
"You are walking in the poorest part of Chamron.\n" +
"This part of the Tartan Avenue is the worst. The stench of the\n" +
"sewers is unbearable and the residence to your north seems quite\n" +
"impossible to live in. An entry to the sewer-system, which seems\n" +
"frequently used, leads down. In south is located a spooky-looking\n" +
"shop. Many suspicious-looking characters seem to have found their\n" +
"way in this part of the city.\n", 4)

