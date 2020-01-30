#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "fortress";
    items[1] = "The knights' fortress.";
}

THREE_EXIT("wizards/nalle/area/i3","east",
"wizards/nalle/area/h2","south",
"wizards/nalle/area/i1","west",
"Hallway in the western part of the fortress.",
"This is a simple hallway, lighted by torches that have been placed\n" +
"on the walls. There is a weapon storage room to the west and\n" +
"the hallway continues to the east.\n", 3)

