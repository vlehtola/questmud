#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "shelves";
    items[1] = "The shelves are full of beautiful instruments and expensive foods.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/alset");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/tie1","north",
"The Von Alset shop",
"This is the luxurious shop of Baronne von Alset. She is an elderly\n" +
"woman and as you step in she considers your clothing and seems to \n" +
"notice right away you won't be a potential buyer. There are many meters \n" +
" of shelves filled with many expensive looking things. \n", 3)

