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
        monster = clone_object("/wizards/nalle/area/trebor");
        move_object(monster, this_object());
    }
    if (!monster2) {
        monster2 = clone_object("/wizards/nalle/area/northam");
        move_object(monster2, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/e5","north",
"wizards/nalle/area/d4","west",
"wizards/nalle/area/e4","northwest",
"The canteen.",
"The smell here is not very pleasant. There are many tables and\n" +
"chairs that are most occupied by hungry knights, who would \n" +
"eat almost anything after their hard training sessions, which is\n" +
"in this case quite a good thing. There is another man, the cook's\n" +
"assistant here, who seems to sell the food.\n", 3)
