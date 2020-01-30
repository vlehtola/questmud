#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "pool";
    items[1] = "It seems you can teleport to the inn by this pool";
}

TWO_EXIT("wizards/nalle/area/darvroom","west",
"wizards/nalle/area/inn","chamron",
"Western part of Darvox's workroom.",
"This must be the teleportation room. There are no windows here\n" +
"only a small pool, with the image of the Inn of the Three Bears\n" +
"in Chamron.\n", 3)
