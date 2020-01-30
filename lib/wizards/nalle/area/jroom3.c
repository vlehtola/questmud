#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster,monster2,monster3;

extra_reset() {
    items = allocate(2);
    items[0] = "path";
    items[1] = "The path is very thin and scarcely visible";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/gpudding");
        move_object(monster, this_object());
    }
    if (!monster2) {
        monster2 = clone_object("/wizards/nalle/area/monsters/gpudding");
        move_object(monster2, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/jroom2","west",
"A clearing.",
"A small clearing in the woods. This seems like the headquarters of\n" +
"the christmas pudding tribe. Their leader, George, used to live in\n" +
"here until he was imprisoned by the knights who considered the\n" +
"puddings as a hostile party. A long vine is dangling from a tree\n" +
"in here, but it seems very frail and, therefore, unclimbable.\n", 3)

