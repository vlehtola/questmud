#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "window";
    items[1] = "The grove and the impaled corpses of the mages are visible through the window";
}

ONE_EXIT("wizards/nalle/area/darvroom","south",
"Northern part of Darvox's workroom.",
"There is a large oaken desk in one corner of the room. There are\n" +
"miscellaneous items with unknown magical powers lying all around\n" +
"the desk. There is also a small window on the northern wall.\n", 3)

