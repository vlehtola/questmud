#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster,monster2,monster3;

extra_reset() {
    items = allocate(2);
    items[0] = "path";
    items[1] = "It is very thin and scarcely visible.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/gpudding");
        move_object(monster, this_object());
    }
    if (!monster2) {
        monster2 = clone_object("/wizards/nalle/area/gpudding");
        move_object(monster2, this_object());
    }
if (!monster3) {
        monster3 = clone_object("/wizards/nalle/area/jill");
        move_object(monster3, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/jroom2","west",
"wizards/nalle/area/a5","vine",
"A clearing.",
"A small clearing in the woods. This seems like the headquarters of\n" +
"of the christmas pudding tribe. Their leader, George, used to live\n" +
"until he was imprisoned by the knights who considered the puddings\n" +
"as a hostile party. A long vine is dangling from a tree here.\n", 3)

