#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "torches";
    items[1] = "They emit a nice warm light.";
}

TWO_EXIT("wizards/nalle/area/g5","north",
"wizards/nalle/area/e5","south",
"A hallway in the eastern part of the fortress.",
"This is an empty hallway in the eastern part of the fortress.\n" +
"There are torches on the walls, emitting a peaceful light.\n" +
"You hear noises of fussing from the north. \n" +
"There is canteen to your south.\n", 3)
