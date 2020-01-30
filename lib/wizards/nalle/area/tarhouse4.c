#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "furniture";
    items[1] = "Most of the furniture in the house is broken and cannot be used";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/assassin");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/tie22","south",
"A house on the Tartan Avenue",
"This house is revolting. The window panes have been replaced with\n" +
"oiled sheets of paper and the furniture is in pitiful state. There\n" +
"is an abhorrent smell floating in the room. \n", 3)
