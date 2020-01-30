#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();


extra_reset() {
    items = allocate(2);
    items[0] = "stairway";
    items[1] = "The stairway is cold to the touch, and is not very comfortable to walk on";
}

TWO_EXIT("wizards/nalle/area/tower1","up",
"wizards/nalle/area/towerd1","down",
"The stairway down.",
"This stairway no longer has the same kind of majestic feeling as the room\n" +
"upstairs. The stairs are made of stone, and are quite crudely carved. You\n" +
"can hear muffled noises from where the stairs are leading but you can't\n" +
"see anything. \n", 3)
