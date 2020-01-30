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
"This is a simple hallway, lighted by torches that have been placed\n" +
"on the walls. To the south there seems to be an altar of some kind\n" +
"but it is hard to make out what there is to the north.\n", 3)

