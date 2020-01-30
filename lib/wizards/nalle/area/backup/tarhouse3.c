#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "desk";
    items[1] = "A wooden reception desk. There is someone standing behind it.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/receptionist");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/tie2","north",
"The Villa Phenlone",
"This is a place where poorer adventurers and all that lot spend their\n" +
"nights in Chamron for a reasonable price. There is an unpleasant smell \n" +
"floating in the air. There is a small reception desk by the door. \n", 3)

