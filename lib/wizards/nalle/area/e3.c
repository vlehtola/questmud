#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "fountain";
    items[1] = "You can't see that far clearly.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/relaxknight");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/f3","north",
"wizards/nalle/area/d3","south",
"Southern part of the churchard.",
"You have arrived into a well-tended garden. Few young\n" +
"knights are walking around and sitting on the benches,\n" +
"constantly reading books. There is a fountain further\n" +
"on to the north, but seems that it is out of water.\n", 3)

