#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "fountain";
    items[1] = "This used to be a fountain, but has now been converted into a flowerbed";
    if (!monster) {
	monster = clone_object("/wizards/nalle/area/monsters/knight");
	move_object(monster, this_object());
    }
}

FOUR_EXIT("wizards/nalle/area/tie1","west",
"wizards/nalle/area/tie2","east",
"wizards/nalle/area/chamron4","north",
"wizards/nalle/area/chamron2","south",
"The Central Square of the City of Chamron.",
"This is the Central Square of the City of Chamron.\n" +
"There are people walking here and there. But after the merchants left\n" +
"the city, the atmosphere has never been the same as in the good old\n" +
"days. In the middle of the square is a dry fountain with some flowers\n" +
"growing in it. The Castle of the Dequan Knights is to your north, the\n" +
"Tartan Avenue is to your east, and the Godfrey Road to your west.\n", 4)

