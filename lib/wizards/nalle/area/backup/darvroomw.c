#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "window";
    items[1] = "You can see the village of Chamron and the river Feuve.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/runningdarvox");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/darvroom","east",
"Western part of Darvox's wormroom.",
"The walls are covered with red curtains. There are long shelves\n" +
"of books here and old small potions, and scrolls are scattered\n" +
"all around the room. There is a small window on the western wall.\n", 3)
