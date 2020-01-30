#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;
extra_reset() {
        if(!monster) {
           monster = clone_object("wizards/manta/castle/dem1.c");
           move_object(monster, this_object());
        }
}

TWO_EXIT("/wizards/manta/hill/room3.c", "north",
           "/wizards/manta/hill/room1.c", "out",
           "Under fortress walls",
           "You are standing under walls of the fortress and can't stop thinking\n" +
           "what kind of army came throught this walls. These walls seem to be at\n" +
           "least 6 feet thick and well made in a fashion what dwarves use.\n", 1)

