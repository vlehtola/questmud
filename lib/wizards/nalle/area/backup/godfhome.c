#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "paintings";
    items[1] = "The paintings on the walls are beautiful, and represent different members of the wealthy Oxfern family.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/oxfern");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/tie12","south",
"The Oxfern residence",
"You have entered Sir Oxfern's residence. The house is extremely beautiful\n" +
"and luxurous. There are various paintings on the walls and there are marvelous\n" +
"antique chairs, closets and other antique furniture scattered around the room. \n", 3)
