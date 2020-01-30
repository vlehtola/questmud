#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;
extra_reset() {
        if(!monster) {
           monster = clone_object("wizards/jenny/linnake/mosut/entry_guard.c");
           move_object(monster, this_object());
        }
}

FOUR_EXIT("/wizards/jenny/linnake/huoneet/path1.c", "west",
           "/wizards/jenny/linnake/huoneet/begin.c", "out",
           "/wizards/jenny/linnake/huoneet/path21.c", "east",
           "/wizards/jenny/linnake/huoneet/hall1.c", "north",
           "You have arrived to the castle of Roxen",
           "You see a hallway to west and east from your position and a huge hall is\n" +
           "located north from you. There are 2 statues of some familiar knights near\n" +
           "you and they look like someone has been taking great care of them. Some\n" +
           "candles are burning on the walls and you can smell something delicious\n" +
           "from the kitchen\n", 1)
