#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {

}

FOUR_EXIT("wizards/bulut/sewer/sewer2","north",
"wizards/bulut/sewer/sewer","south",
"wizards/bulut/sewer/sewer","east",
"wizards/bulut/sewer/sewer","west",
"Crossing in the sewer system.",
"Yuch, You still cant get used to the smell of this place.\n" +
"The walls of this place are made of bricks, and between every rock grows\n" +
"some sort of moss. A tiny blink of light can be seen upwards from here\n" +
"But it still is quite dark here. You wish you never came here.\n", 2)
