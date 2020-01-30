#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "chest";
    items[1] = "You start opening the chest, but quickly close it again as a head peeks out";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/lydia");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/tie22","north",
"Lydia's black magic shop",
"This is Lydia's black magic shop. There are many drawers, shelves \n" +
"and bottles that are filled with most bizarre objects. There is a small chest \n" +
"in the northeastern corner of the room. The other people in the room seem to\n" +
"be looking with intrest at the scrolls and bottles that have been prepared by Lydia.\n", 3)

