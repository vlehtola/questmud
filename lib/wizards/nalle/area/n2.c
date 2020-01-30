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
        monster = clone_object("/wizards/nalle/area/monsters/knight2");
        move_object(monster, this_object());
    }
set_not_out();
}

TWO_EXIT("wizards/nalle/area/m2","south",
"wizards/nalle/area/i5","up",
"Staircase up, on the bottom floor.",
"This seems to be the prison part of the fortress. There is a\n" +
"flegmatic guard standing here who should prevent you from\n" +
"accessing the cells, but doesn't seem to care. There is a text\n" +
"written on the wall.\n", 3)
