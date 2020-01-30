#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "stairway";
    items[1] = "The stairway leads up into Darvox's quarters";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/alevric");
      move_object(monster, this_object());
     }
}

TWO_EXIT("wizards/nalle/area/tower8","up",
"wizards/nalle/area/tower6","down",
"The 7th floor, Alevric's room.",
"This is where Alevric, Darvox's main apprentice spends his free time. \n" +
"The room is simply furnished but a majestic stairway leads up, into \n" +
"Darvox's room. \n", 3)
