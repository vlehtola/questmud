#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "furniture";
    items[1] = "They are mostly broken and most of them c'ant be used.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/assassin");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/tie22","south",
"A house on the Tartan avenue",
"This house is revolting. The windowscreens have been replaced with\n" +
"oiled sheets of paper, and the furniture is in a pitiful state. There \n" +
"is an abhorrent smell in the room. \n", 3)
