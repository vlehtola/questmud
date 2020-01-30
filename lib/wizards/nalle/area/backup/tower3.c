#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "shelves";
    items[1] = "An innumerable amount of books have been placed in the shelves";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/redrobe");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/tower2","down",
"The third floor library.",
"This library that is open to all the occupants of the tower. There are long \n" +
"shelves filled with books from wall to wall, and the flurrying of the robes \n" +
"is clearly audible as the young mages hurry from book to book attempting\n" +
"to learn as much as possible. \n", 3)
