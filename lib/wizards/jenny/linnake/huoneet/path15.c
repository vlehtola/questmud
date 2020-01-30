#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;
extra_reset() {
        if(!monster) {
           monster = clone_object("wizards/jenny/linnake/mosut/man.c");
           move_object(monster, this_object());
        }
}

ONE_EXIT("/wizards/jenny/linnake/huoneet/path14.c", "west",
           "You arrived to a dead end.",
           "You arrived to a dead end. When you look walls closely you can see\n" +
           "lots of small holes on them. Some torches are burning near and they\n" +
           "light your way nicely. At west you see the same narrow hallway where\n" +
           "you came few moments ago.\n", 1)
