#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "churchard";
    items[1] = "A beautiful churchard.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/knight2");
        move_object(monster, this_object());
    }
}

FOUR_EXIT("wizards/nalle/area/c3","south",
"wizards/nalle/area/d4","east",
"wizards/nalle/area/d2","west",
"wizards/nalle/area/e3","north",
"Inside the Fortress.",
"You have just passed under the portcullis, and into the fortress.\n" +
"The fortress is almost completely made of stone, there are only\n" +
"a few wooden support-planks here and there. You notice some\n" +
"sort of holy place to your west, and a churchard to the north\n", 3)
