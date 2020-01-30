#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "flags";
    items[1] = "They are green and white flags of Chamron.";
}

FOUR_EXIT("wizards/nalle/area/tie12","west",
"wizards/nalle/area/chamron3","east",
"wizards/nalle/area/mayoroff","north",
"wizards/nalle/area/luxshop","south",
"On the Godfrey Road",
"You have arrived to the Godfrey Road.\n" +
"This is the wealthiest part of Chamron, with luxurious shops\n" +
"and beautiful residences. The green and white flags of Chamron \n" +
"give a majestic feeling to the road, and this road is in a very great\n" +
"contrast to the tartan road, that is in the eastern part of Chamron. \n" +
"The Central square is to your east and the road continues to the west.\n" +
"There is a shop to your south and the mayors office to your north.\n", 5)

