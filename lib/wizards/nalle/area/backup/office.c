#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "desk";
    items[1] = "A modern working desk, similar to the one downstairs";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/mayor");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/mayoroff","down",
"The Mayor's office",
"This is Mayor's office. The bookshelves and desks are messy and the curtains are drawn. There \n" +
"seems to be something wrong. The mayor himself is walking around the room, deep in thought \n" +
"and only notices you once you wave your hand infront of his nose. There is a small bed in\n" +
"the corner of the room and judging by his clothes the mayor seems to have slept with his clothes on. \n", 3)

