#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "fountain";
    items[1] = "A beautiful fountain. It has been converted into a flowerbed.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/relaxknight");
        move_object(monster, this_object());
    }
}

FOUR_EXIT("wizards/nalle/area/g3","north",
"wizards/nalle/area/f4","east",
"wizards/nalle/area/f2","west",
"wizards/nalle/area/e3","south",
"In the middle of the churchard.",
"You are in the middle of a  well tended garden. \n" +
"The ambiance is very calm and no sounds of \n" +
"battle or training can be heard here. There is a \n" +
"large fountain here but it is out of water.\n", 3)

