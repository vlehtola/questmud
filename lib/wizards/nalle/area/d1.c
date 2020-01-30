#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "benches";
    items[1] = "A long row of benches";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/priest");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/e1","north",
"wizards/nalle/area/d2","east",
"wizards/nalle/area/e2","northeast",
"At the altar.",
"This is where the knights come to meditate and to understand their holy\n" +
"mission. There is a row of benches where one can sit and listen to the\n" +
"High Priest's sermons. A big altar with carefully-made carvings is\n" +
"standing in the end of the aisle.\n", 3)
