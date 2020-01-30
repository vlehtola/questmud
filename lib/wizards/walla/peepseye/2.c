#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/walla/peepseye/monsters/snail");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/walla/peepseye/1", "south",
         "wizards/walla/peepseye/3", "north",
         "The path to the forest",
         "As the trees start getting bigger and bigger, the forest gets darker. You start \n" +
         "hearing some sort of music from up ahead. \n", 3)

