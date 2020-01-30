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
"This is where the Mayor of Chamron works, or at least his secretary does. One doesn't \n" +
"see the mayor much anymore and most of the easier work has been given to the secretary. The \n" +
"citizens are getting quite curious: What is  keeping the mayor so busy? Or is he starting to get\n" +
"get too old for his job. The secretary is working at her desk next to the staircase to the mayor's office. \n", 3)

