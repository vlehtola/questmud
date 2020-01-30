#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "stairway";
    items[1] = "The stairway leads up into Darvox's quarters";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/demon");
      move_object(monster, this_object());
     }
}

TWO_EXIT("wizards/nalle/area/darvrooms","up",
"wizards/nalle/area/tower7","down",
"The entry to Darvox's quarters, on the 8th floor",
"This room is indeed very majestic, but not welcoming. This is the\n" +
"entry to the Great Mage's workroom, and a demon has been summoned\n" +
"to keep away any unwanted guests.\n", 3)
