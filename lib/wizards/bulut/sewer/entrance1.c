#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
    }

TWO_EXIT("wizards/bulut/sewer/ulos","out",
"wizards/bulut/sewer/entrance2","north",
"A dull looking yard.",
"You are standing on a dull looking yard. There are no trees or any animals.\n" +
"A terrible smell is coming from the road, leading to north.\n", 3)

