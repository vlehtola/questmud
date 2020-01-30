#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster,monster2;
extra_reset() {
        if(!monster) {
           monster = clone_object("wizards/jenny/linnake/mosut/jail_guard.c");
           move_object(monster, this_object());
        }
        if(!monster2) {
           monster2 = clone_object("wizards/jenny/linnake/mosut/jail_guard.c");
           move_object(monster2, this_object());
        }
}

TWO_EXIT("/wizards/jenny/linnake/huoneet/prison21.c", "west",
           "/wizards/jenny/linnake/huoneet/prison19.c", "south",
           "You are walking in a narrow hallway",
           "You are walking in a narrow hallway that leads to the captains\n" +
           "room. There are some torches burning near you and the floor is\n" +
           "very dusty. This place smells like puke, old socks and liquor.\n" +
           "You can hear prisoners screaming from their cells.\n", 1)
