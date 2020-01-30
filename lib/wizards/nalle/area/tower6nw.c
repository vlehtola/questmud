#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/alamrot");
      move_object(monster, this_object());
     }
}

ONE_EXIT("wizards/nalle/area/tower6n","east",
"The northwestern part of the 6th floor, a small cell.",
"The room you have entered seems like a small cell. The room is\n" +
"nevertheless in a fairly good condition and lacks the smell of\n" +
"manure that is common to the normal prisons. There are two\n" +
"chains, which are used to keep the prisoners still, attached\n" +
"in the wall.\n", 3)

