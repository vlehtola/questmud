#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "chain";
    items[1] = "That should keep the little fella still";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/alamrot");
      move_object(monster, this_object());
     }
}

ONE_EXIT("wizards/nalle/area/tower6n","east",
"The northwestern part of the 6th floor, a small cell.",
"The room you have entered seems like a small cell. The room is  \n" +
"nevertheless in a fairly good shape and lacks the smell of manure \n" +
"that is common in normal prisons. There is currently only one occupant\n" +
"who is chained to to the wall by his leg. \n", 3)

