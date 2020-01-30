#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "foutain";
    items[1] = "You cannot see the fountain clearly from this far";
}

TWO_EXIT("wizards/nalle/area/i3","north",
"wizards/nalle/area/g3","south",
"The northern part of the churchard.",
"You are now in the northeastern part of the churchard.\n" +
"The garden is well-tended and there is a paved path\n" +
"leading to north and south. In south you can faintly\n" +
"see a fountain and some knights relaxing around it.\n", 3)

