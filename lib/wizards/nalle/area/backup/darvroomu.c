#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster,monster2;

extra_reset() {
    items = allocate(2);
    items[0] = "throne";
    items[1] = "A massive black throne, behind a long desk.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/realdarvox");
        move_object(monster, this_object());
    }

if (!monster2) {
        monster2 = clone_object("/wizards/nalle/area/darvguard");
        move_object(monster2, this_object());
    }
}



ONE_EXIT("wizards/nalle/area/darvroom","down",
"Darvox's Lounge",
"The dimensions of this room are huge. The ceiling is 20 feet high. There \n" +
"is a long wooden desk in the northern part of the room. Behind it there is\n" +
"a black throne, with a black robed man sitting on it. \n", 3)
