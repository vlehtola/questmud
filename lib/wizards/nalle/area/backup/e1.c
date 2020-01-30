#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "benches";
    items[1] = "A row of benches.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/knight3");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/d1","south",
"wizards/nalle/area/e2","east",
"wizards/nalle/area/f1","north",
"At a row of benches near the altar.",
"This is where the knights come to meditate, and to understand\n" +
"their holy mission. There is a row of benches where one can sit\n" +
"and listen to the high priest's sermons. You can hear steady \n" +
"talking and humming from the south, where the altar is.\n", 3)
