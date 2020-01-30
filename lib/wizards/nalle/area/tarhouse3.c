#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "desk";
    items[1] = "A wooden receptionist's desk.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/receptionist");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/tie2","north",
"The Villa Phenlone",
"This is a place where poorer adventurers and all of that lot spend their\n" +
"nights in Chamron. The prices seem very reasonable. There is an unpleasant\n" +
"smell floating in the air. A small receptionist's desk is standing next to\n" +
"the door.\n", 3)

