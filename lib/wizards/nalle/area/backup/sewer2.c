#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "chair";
    items[1] = "It  seems obvious the man sitting on it is the leader";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/bernard");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/sewer1","east",
"The Thieves' meeting place.",
"This is a rather pleasant place, compared to the entrance. This is where the\n" +
"thieves of Chamron come to buy their equipment and exchange stories. The \n" +
"room seems empty, except for the northeastern corner where a thin man is\n" +
"sitting on a satin chair. There is a tunnel leading to the entrance. \n", 3)

