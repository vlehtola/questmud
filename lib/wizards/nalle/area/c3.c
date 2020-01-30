#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "fortress";
    items[1] = "The knights' fortress.";
}

FOUR_EXIT("wizards/nalle/area/d3","north",
"wizards/nalle/area/c2","west",
"wizards/nalle/area/c4","east",
"wizards/nalle/area/b3","south",
"Entrance to the fortress.",
"You are now at the end of the cobblestone road at the entrance\n" +
"of the fortress. There is a large opening in the wall of the fortress\n" +
"from which you could enter.\n", 3)
