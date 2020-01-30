#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "text";
    items[1] = "It says the most ferocious criminals are located in the southern part";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/george");
        move_object(monster, this_object());
    }
set_not_out();
}

ONE_EXIT("wizards/nalle/area/m2","west",
"A small cell.",
"This is a small room with sturdy looking stone walls. The\n" +
"floor is covered with hay, on which the occupant must sleep\n" +
"and perform all its other duties. There is no lavatory, which\n" +
"is a major drawback to the comfort of the room.\n", 3)
