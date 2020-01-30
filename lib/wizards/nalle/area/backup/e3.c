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
        monster = clone_object("/wizards/nalle/area/relaxknight");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/f3","north",
"wizards/nalle/area/d3","south",
"Southern part of the churchard.",
"You have arrived into a well tended garden. Young knights\n" +
"are walking around and sitting on the benches reading \n" +
"books. There is a fountain further up to the north, but \n" +
"it seems it is out of water.\n", 3)

