#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/walla/jerusalem/monsters/citizen");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/walla/jerusalem/armenia/23", "east",
         "wizards/walla/jerusalem/armenia/21", "west",
         "wizards/walla/jerusalem/armenia/pen12","south",
         "Rabbath-Ammon, the mainway",
         "The Rabbath-Ammon is now nothing but a small path, which has been left\n" +
         "between the houses. There is nothing of great importance here,except maybe\n" +
         "that sewerlid, attempted to be hidden under the dust.\n", 3)
