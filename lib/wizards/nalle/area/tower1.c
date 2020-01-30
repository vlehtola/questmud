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
"In the hall",
"This room has an eerie feeling about it. The walls are all wine-red,\n" +
"as are the satin curtains which are used to cover the paintings,\n" +
"that seem to have been on the walls for centuries. There is a stair-\n" +
"way leading up and another one leading down. The passage leading out\n" +
"of the tower seems to be open.\n", 3)
