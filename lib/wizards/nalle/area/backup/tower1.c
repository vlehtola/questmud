#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();


extra_reset() {
    items = allocate(2);
    items[0] = "paintings";
    items[1] = "The paintings seem old, and it is hard to distinguish who they represent";
}

THREE_EXIT("wizards/nalle/area/tower2","up",
"wizards/nalle/area/darvpath2","out",
"wizards/nalle/area/towerd","down",
"In the hall.",
"This room has an eerie feeling about it. The walls are all wine red, as are\n" +
"the satin curtains that are used to cover the paintings that seem to have been on\n" +
"the walls for centuries. There is a stairway leading up and another one\n" +
"leading down. The passage you enter the tower from, still seems open. \n", 3)
