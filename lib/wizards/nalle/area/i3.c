#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
}

THREE_EXIT("wizards/nalle/area/i4","east",
"wizards/nalle/area/h3","south",
"wizards/nalle/area/i2","west",
"Hallway in the northern part of the fortress.",
"This is a simple hallway, lit by torches that have been placed\n" +
"on the walls. There is a weapon storage room in the west, the\n" +
"hallway continues to east. The churchard is to your south.\n", 3)

