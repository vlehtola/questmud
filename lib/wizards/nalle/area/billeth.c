#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "sofa";
    items[1] = "A red, comfortable sofa";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/mrbilleth");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/godfhome2","north",
"Mr. Billeth's house.",
"The house does not look at all as luxurious as from outside. The room is\n" +
"furnished with bookshelves, a sofa and a desk which is situated next to\n" +
"the sofa. There is a large glass of lemonade and a few books on the table.\n" +
"The sofa has been drug away from the wall. The gap seems to be big enough\n" +
"for someone to hide in it.\n", 3)
