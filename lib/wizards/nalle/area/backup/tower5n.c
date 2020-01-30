#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster,monster2;

extra_reset() {
    items = allocate(2);
    items[0] = "staircase";
    items[1] = "It leads up to the 6th floor";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/blackrobe");
        move_object(monster, this_object());
    }
    if (!monster2) {
        monster2 = clone_object("/wizards/nalle/area/blackrobe");
        move_object(monster2, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/tower6n","up",
"wizards/nalle/area/tower5","south",
"A room filled with illusions, on the 5th floor.",
"This is the training area for the black robes. The sound of \n" +
"thunderbolts and growling illusionary dragons is deafening.\n" +
"Two mages are testing their skills here right now. There is \n" +
"a staircase leading up in the northern corner of the room\n", 3)
