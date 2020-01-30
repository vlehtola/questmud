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

THREE_EXIT("wizards/walla/area/estreet2", "south",
                 "wizards/walla/area/ispep4", "west",
         "wizards/walla/area/egate", "east",
"On Eastern street ",
         "You are standing on the eastern street in  Jericho.\n" +
         "High above is a vulture looking to find a corpse. \n", 3)
