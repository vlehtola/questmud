#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
    if (!present("sign")) {
         move_object("wizards/walla/strahd/obj/sign", this_object());
    }
    if (!items) {
        items = allocate(2);
        items[0] = "haystacks";
        items[1] = "Haystacks lie along the way, it seems asthough it has been harvesting season\n" +
                   "not long ago. The fresh hay still smells good.";
    }
}
TWO_EXIT("wizards/walla/strahd/tpath", "east",
         "out: 185 43", "west",
         "On a road, leading up to the mountainous area",
         "The road is a usual road, one as you could find a enormous number in the countryside.\n" +
         "Haystacks lie on both sides of the road, and a sign, which is about to fall, are here.\n" +
         "Up ahead the plains continue, and the road seems to bend. \n", 3)
