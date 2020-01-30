#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "tables";
    items[1] = "There are large cauldrons full of soup on them.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/eatingknight");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/d3","west",
"wizards/nalle/area/d5","east",
"wizards/nalle/area/e4","north",
"The western part of the canteen.",
"The smell here is not very pleasant. There are many tables and\n" +
"chairs that are most occupied by hungry knights, who would \n" +
"eat almost anything after their hard training sessions, which is\n" +
"in this case quite a good thing.\n", 3)
