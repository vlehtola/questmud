#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "window";
    items[1] = "Through the window you can see the village of Chamron and the river Feuve";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/wraith");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/darvroom","east",
"Western part of Darvox's workroom.",
"The walls are covered with red curtains. There are long bookshelves\n" +
"in here. Few old-looking potions and scrolls are scattered all around\n" +
"the room's floor. There is a small window on the western wall.\n", 3)
