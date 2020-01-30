#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();


extra_reset() {
    items = allocate(2);
    items[0] = "tower";
    items[1] = "The tower looms in front of you like a symbol of death";
}

TWO_EXIT("wizards/nalle/area/tower1","enter",
"wizards/nalle/area/darvpath","west",
"Infront of the Tower of High Sorcery.",
"This place is not at all inviting. A huge black tower looms up into\n" +
"the skies and the smell of the impaled corpses that have been left\n" +
"to decay on the sharp poles is revolting. The walls of the tower\n" +
"are scaly and seem impossible to climb up even with ropes.\n", 3)
