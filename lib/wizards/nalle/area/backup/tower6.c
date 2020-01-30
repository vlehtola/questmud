#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "stairway";
    items[1] = "It seems to lead to a workroom of some kind";
}

TWO_EXIT("wizards/nalle/area/tower6n","north",
"wizards/nalle/area/tower7","up",
"A room on the 6th floor.",
"There is a large winding staircase leading up, towards the tower's\n" +
"masters workroom. This room itself is poorly decorated, and only \n" +
"seems to be the link between the workrooms and the rest of the tower.\n", 3)
