#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "sandbag";
    items[1] = "A ripped and torn sandbag.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/supknight");
        move_object(monster, this_object());
    }
}

FOUR_EXIT("wizards/nalle/area/b5","east",
"wizards/nalle/area/a4","south",
"wizards/nalle/area/b3","west",
"wizards/nalle/area/c4","north",
"A grassy trainingfield.",
"You are on a grassy field. There are sandbags and straw horses\n" +
"here and there. The fortress is roughly to your north and the\n" +
"path to your west. There is a seat for the supervisor here. \n", 3)
