#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "bushes";
    items[1] = "They are spiky and not so nice.";
}

TWO_EXIT("wizards/nalle/area/f3","west",
"wizards/nalle/area/g4","north",
"The eastern part of the churchard.",
"You are now in the northeastern part of the churchard.\n" +
"The garden is not so well tended here and the spiky rose\n" +
"bushes make your moving a bit unpleasant but not\n" +
"impossible.\n", 3)
