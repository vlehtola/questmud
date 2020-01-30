#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "stairway";
    items[1] = "The stairway seems to lead into a workroom of some kind";
}

TWO_EXIT("wizards/nalle/area/tower6n","north",
"wizards/nalle/area/tower7","up",
"A room on the 6th floor",
"There is a large, winding staircase leading up towards the tower's\n" +
"master's workroom. This room itself is poorly decorated, and its\n" +
"only purpose seems to be the linking the workroom to the rest of\n" +
"the tower.\n", 3)
