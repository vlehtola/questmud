#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/walla/peepseye/monsters/ferry");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/walla/peepseye/ferry/ferry", "out",
            "In the Cabin",
         "In here is a foul smell of some rotten foods etc. An old man is sitting in one corner.\n" +
         "It seems that he is the one driving this ship. He seems to be very very bored. \n", 3)
