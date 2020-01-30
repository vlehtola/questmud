#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;
extra_reset() {
        if(!monster) {
           monster = clone_object("wizards/jenny/linnake/mosut/thief.c");
           move_object(monster, this_object());
        }
}

ONE_EXIT("/wizards/jenny/linnake/huoneet/kitchen3.c", "west",
           "You are in the storage room",
           "You are in the storage of kitchen, you see barrels full of wine\n" +
           "and some other barrels full of water. There are also large stacks\n" +
           "of meat, fish and other food supplies. In the corner there are\n" +
           "some rats eating potatoes from an open sack and some bats are\n" +
           "sleeping nearby.\n", 1)
