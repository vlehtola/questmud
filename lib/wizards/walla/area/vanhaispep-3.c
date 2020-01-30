#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/citizen");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/walla/area/ispep-2", "east",
         "wizards/walla/area/ispep-4", "west",
         "On Ispep street ",
         "You are at the old sewer entrance, unfortunately, the sewerlid has rusted and\n" +
         "is unable to be opened, at the moment.\n" +
         "But fear not, help is on the way, and the plumber has been called to help. \n", 3)
