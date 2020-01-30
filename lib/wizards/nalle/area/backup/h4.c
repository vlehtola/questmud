#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/nalle/area/engineer");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/i4", "north",
"wizards/nalle/area/i5","northeast",
"wizards/nalle/area/h5", "east",
"The war room",
"This is a well lit room with all sorts of papers and boards\n" +
"on every wall. There are also many desks and chairs on\n" +
"which some high ranking knights are sitting on and \n" +
"sratching their heads while listening to the engineers. \n", 3)

