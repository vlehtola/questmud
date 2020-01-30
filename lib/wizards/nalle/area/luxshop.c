#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "shelves";
    items[1] = "The shelves are full of beautiful instruments and expensive foods";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/alset");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/tie1","north",
"The Von Alset's shop.",
"This is the luxurious shop of Baronne von Alset. She is an elderly\n" +
"woman and has been the owner of this shop for many decades. The\n" +
"Von Alset's shop is very familiar all around the realm. There are\n" +
"many meters of shelves filled with many expensive-looking things.\n", 3)

