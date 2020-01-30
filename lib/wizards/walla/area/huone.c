#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(1);
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/lguard");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/walla/area/lebway1", "north",
         "wizards/walla/area/cem23", "up"

"Under the cemetary ",
         "The cemetary has gone away, and you find yourself looking at a man of great size.\n" +
         "He seems to guard something important.\n", 1)
