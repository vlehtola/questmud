#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "fortress";
    items[1] = "The knights' fortress.";
}

THREE_EXIT("wizards/nalle/area/i5","east",
"wizards/nalle/area/h4","south",
"wizards/nalle/area/i3","west",
"Hallway in the northern part of the fortress.",
"This is a simple hallway, lighted by torches that have been placed\n" +
"on the walls. There is a staircase leading up and down to your east\n" +
"There is some sort of office to your south.\n", 3)

