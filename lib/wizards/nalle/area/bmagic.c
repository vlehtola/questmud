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
        monster = clone_object("/wizards/nalle/area/monsters/lydia");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/tie22","north",
"Lydia's black magic shop.",
"This is Lydia's black magic shop. There are many drawers, shelves\n" +
"and bottles that are filled with most bizarre objects. There is a\n" +
"small chest in the northeastern corner of the room. The other people\n" +
"in the room seem to be looking at the scrolls and bottles that have\n" +
"been prepared by Lydia with great interest.\n", 3)

