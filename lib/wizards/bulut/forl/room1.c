#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
if (!present("painting")) {
move_object("wizards/bulut/forl/painting.c", this_object());
    }
}

TWO_EXIT("wizards/bulut/forl/house3","east",
"wizards/bulut/forl/room2.c","up",
"Inside of a house",
"Straircase is here, leading up.\n",3)
