#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "portal";
    items[1] = "This is the portal that leads to Elraak's room";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/blackrobe");
      move_object(monster, this_object());
     }
}

TWO_EXIT("wizards/nalle/area/tower5n","north",
"wizards/nalle/area/tower2n","portal",
"The fifth floor",
"This is a lounge of some kind for the black-robed apprentices. The smell\n" +
"of the black-robed mages' decaying spell-components is strong, and some\n" +
"of the mages are summoning demons and creating illusions with their\n" +
"arcane powers to kill time.\n", 3)
