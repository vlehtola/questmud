#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "table";
    items[1] = "There is a huge oaken table in the middle of the room.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/norp");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/chamron2","east",
"The Inn of the Three Bears.",
"This is the local inn. You feel yourself relax almost instantly as you\n" +
"enter the cosy room. A beautiful table, meant for the customers, stands\n" +
"in the middle of the room. This sure is a great place to get your mind\n" +
"off from your normal worries.\n", 3)