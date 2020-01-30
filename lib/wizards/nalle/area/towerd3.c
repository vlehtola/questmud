#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster,monster2;

extra_reset() {
    items = allocate(2);
    items[0] = "stairway";
    items[1] = "All you can see in the stairway is darkness";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/spectre");
        move_object(monster, this_object());
    }
    if (!monster2) {
        monster2 = clone_object("/wizards/nalle/area/monsters/spectre");
        move_object(monster2, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/towerd2","up",
"wizards/nalle/area/towerd4","down",
"Utter and complete darkness",
"There seems to be a dense magical darkness surrounding you. You\n" +
"sense an exit upwards and another one downwards, though.\n", 1)

