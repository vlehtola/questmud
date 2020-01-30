#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "desk";
    items[1] = "A modern working desk";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/secretary");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/tie1","south",
"wizards/nalle/area/office","up",
"The Mayor's secretary's room",
"This is where the Mayor of Chamron works, or at least his secretary does. \n"+
"One doesn't see the mayor much anymore and most of the easier work has been \n"+
"given to the secretary. The citizens are getting quite curious: What is\n"+
"keeping the mayor so busy? Or is he starting to get too old for his job.\n"+
"The secretary is working at her desk next to the staircase to the mayor's\n"+
"office. \n", 3)

