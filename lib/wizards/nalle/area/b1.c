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
        monster = clone_object("/wizards/nalle/area/monsters/trknight");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/c1","north",
"wizards/nalle/area/b2","east",
"wizards/nalle/area/a1","south",
"A grassy trainingfield.",
"You are on a grassy field. There are sandbags and straw horses\n" +
"here and there. The fortress is roughly to your north and the\n" +
"city of Chamron to your south.\n", 3)

