#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster,monster2;

extra_reset() {
    items = allocate(2);
    items[0] = "tables";
    items[1] = "There are large cauldrons of noodles on them";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/trebor");
        move_object(monster, this_object());
    }
    if (!monster2) {
        monster2 = clone_object("/wizards/nalle/area/monsters/northam");
        move_object(monster2, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/e5","north",
"wizards/nalle/area/d4","west",
"wizards/nalle/area/e4","northwest",
"The canteen.",
"The smell here is not very pleasant. The most of the many tables and\n" +
"chairs are occupied by hungry Dequan Knights. Seems that the knights\n" +
"would eat almost anything after their hard training sessions, which is\n" +
"in this case quite a good thing. A small booth near the eastern wall\n" +
"seems to be a place for the cook and his assistant, whose duty is to\n" +
"sell the food for the hungry customers.\n", 3)
