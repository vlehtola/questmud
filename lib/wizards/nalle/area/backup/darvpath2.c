#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();


extra_reset() {
    items = allocate(2);
    items[0] = "tower";
    items[1] = "The tower looms over you, like a symbol of death";
}

TWO_EXIT("wizards/nalle/area/tower1","enter",
"wizards/nalle/area/darvpath","west",
"Infront of the Tower of High Sorcery.",
"This place is not at all inviting. A huge black tower looms up into the skies \n" +
"and the smell of the impaled corpses that have been left to decay on the sharp \n" +
"poles is revolting. The walls of the tower are scaly and seem impossible to climb\n" +
"even with ropes. \n", 3)
