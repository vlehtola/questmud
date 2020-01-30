#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "bushes";
    items[1] = "The bushes here are spiky and not so nice";
}

TWO_EXIT("wizards/nalle/area/g3","west",
"wizards/nalle/area/f4","south",
"The northeastern part of the churchard.",
"You are now in the northeastern part of the churchard.\n" +
"The garden is not so well tended in here and the spiky\n" +
"rose-bushes make your moving a bit unpleasant, but not\n" +
"impossible.\n", 3)

