#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "desk";
    items[1] = "A modern working-desk, similar to the one downstairs";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/mayor");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/mayoroff","down",
"The Mayor's office",
"This is the mayor's office. The bookshelves and desks are messy and the\n" +
"curtains are drawn. There seems to be very tense atmosphere surrounding\n" +
"this room. There is a small bed in the corner of the room, and judging by\n" +
"the clothes thrown next to the bed, someone has been sleeping in the bed\n" +
"with its clothes on.\n", 3)

