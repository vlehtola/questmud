#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "torches";
    items[1] = "The torches emit a pure, warm light";
}

TWO_EXIT("wizards/nalle/area/h5","north",
"wizards/nalle/area/f5","south",
"A hallway in the eastern part of the fortress.",
"This is an empty hallway in the eastern part of the fortress.\n" +
"There are torches on the walls, emitting a peaceful light.\n" +
"You hear noises of fussing from north and south. There seems\n" +
"to be a staircase further to your north.\n", 3)
