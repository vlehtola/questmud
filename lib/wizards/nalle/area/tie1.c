#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "flags";
    items[1] = "The flags illustrate a green and white emblem of Chamron";
}

FOUR_EXIT("wizards/nalle/area/tie12","west",
"wizards/nalle/area/chamron3","east",
"wizards/nalle/area/mayoroff","north",
"wizards/nalle/area/luxshop","south",
"On the Godfrey Road",
"You are walking along the Godfrey Road.\n" +
"This is the wealthiest part of Chamron. The streetsides are filled with\n" +
"luxurious shops and beautiful residences. The green and white flags of\n" +
"Chamron give a majestic feeling over the road, and this road is a great\n" +
"contrast to the Tartan Avenue, which is in the eastern part of Chamron.\n" +
"The Central Square is to your east and the road continues to the west.\n" +
"There is a shop to your south and the mayor's office to your north.\n", 5)

