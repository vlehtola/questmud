#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster,monster2;

extra_reset() {
    items = allocate(2);
    items[0] = "swamp";
    items[1] = "The smell of the decaying plants is awful";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/spectre2");
        move_object(monster, this_object());
    }
    if (!monster2) {
        monster2 = clone_object("/wizards/nalle/area/spectre2");
        move_object(monster2, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/pathe","west",
"wizards/nalle/area/darvpath","east",
"The western part of the grove.",
"You are in the swamps between Chamron and the Darvox's tower.\n" +
"Your movement was interrupted by two spectres, that materialized \n" +
"right infront of you, as you were leaving. It seems Darvox \n" +
"wanted you to know that your visit wasn't left unnoticed. \n", 3)
