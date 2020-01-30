#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "torches";
    items[1] = "The torches shed a warm light over the room";
}

TWO_EXIT("wizards/nalle/area/h1","north",
"wizards/nalle/area/f1","south",
"Hallway in the western part of the fortress.",
"This is a simple hallway, lit by torches that have been placed on\n" +
"the walls. In south there seems to be an altar of some kind, but\n" +
"it is hard to see what there might be in the north.\n", 3)

