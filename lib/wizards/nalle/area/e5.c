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
        monster = clone_object("/wizards/nalle/area/monsters/eatingknight");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/e4","west",
"wizards/nalle/area/d5","south",
"wizards/nalle/area/f5","north",
"The northern part of the canteen.",
"The smell here is not very pleasant. There are many tables and\n" +
"chairs that are most occupied by hungry knights, who would \n" +
"eat almost anything after their hard training sessions, which is\n" +
"in this case quite a good thing.\n", 3)
