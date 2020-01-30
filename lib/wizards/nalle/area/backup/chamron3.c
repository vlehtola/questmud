#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "fountain";
    items[1] = "This used to be a fountain, but has now been converted to a flowerbed.";
    if (!monster) {
	monster = clone_object("/wizards/nalle/area/knight");
	move_object(monster, this_object());
    }
}

FOUR_EXIT("wizards/nalle/area/tie1","west",
"wizards/nalle/area/tie2","east",
"wizards/nalle/area/chamron4","north",
"wizards/nalle/area/chamron2","south",
"The Central Square of the City of Chamron",
"This is the Central Square of the City of Chamron.\n" +
"There are people walking here and there, but not as much as \n" +
"in the good old days, since most of the commercants have left.\n" +
"In the middle of the square is a dry fountain, with flowers in it..\n" +
"The castle of the Dequan Knights is to your north, the Tartan \n" +
"Avenue is to your east, and the Godfrey Road to your west.\n", 4)

