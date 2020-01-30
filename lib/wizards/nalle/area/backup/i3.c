#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "fortress";
    items[1] = "The knights' fortress.";
}

THREE_EXIT("wizards/nalle/area/i4","east",
"wizards/nalle/area/h3","south",
"wizards/nalle/area/i2","west",
"Hallway in the northern part of the fortress.",
"This is a simple hallway, lighted by torches that have been placed\n" +
"on the walls. There is a weapon storage room to the west and\n" +
"the hallway continues to the east. The churchard is to the south.\n", 3)

