#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/engineer");
        move_object(monster, this_object());
    }
}

THREE_EXIT("wizards/nalle/area/i4", "north",
"wizards/nalle/area/i5","northeast",
"wizards/nalle/area/h5", "east",
"The war room.",
"This is a well-lit room with all sorts of papers and boards\n" +
"attached on every walls. There are also many desks and chairs\n" +
"on which some high ranking knights are sitting and scratching\n" +
"their heads while listening to the engineers.\n", 3)

