#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
}

THREE_EXIT("wizards/nalle/area/i5","east",
"wizards/nalle/area/h4","south",
"wizards/nalle/area/i3","west",
"Hallway in the northern part of the fortress.",
"This is a simple hallway, lit by torches that have been placed\n" +
"on the walls. There is a staircase leading up and down to your\n" +
"east. There is also some sort of an office to your south.\n", 3)

