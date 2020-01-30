#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    items = allocate(2);
    items[0] = "flags";
    items[1] = "They are green and white flags of Chamron.";
}

FOUR_EXIT("wizards/nalle/area/godfhome3","west",
"wizards/nalle/area/tie1","east",
"wizards/nalle/area/godfhome","north",
"wizards/nalle/area/godfhome2","south",
"Further on the Godfrey Road",
"Further up the Godfrey Road.\n" +
"This is where the wealthy people of Chamron live. There are houses\n" +
"to the north and to the south. The houses are made of beautiful \n" +
"white rock, and the banners of the inhabiting families are hung over \n" +
"the entrances. To the west there is the school of Chamron, but only the\n" +
"wealthy people can have their children go there. The only possibility for the\n" +
"poorer children to get education is to go learn in the Temple with the monks.\n", 5)

