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

THREE_EXIT("wizards/walla/jerusalem/armenia/22", "east",
         "wizards/walla/jerusalem/armenia/house2ent", "west",
         "wizards/walla/jerusalem/armenia/31","south",
         "Rabbath-Ammon, the mainway",
         "The Rabbath-Ammon still makes its long journey through the armenian quarters\n" +
         "between the houses. South from here, starts the Hart El Yahud, which is, the\n" +
         "Jewish section of the Armenian Quarters.\n", 3)

