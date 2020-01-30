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
        monster = clone_object("/wizards/nalle/area/mrbilleth");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/godfhome2","north",
"Mr. Billeth's house",
"The house does not look at all as luxurious as from outside. The room is furnished \n" +
"with bookshelves a few sofas and a desk that is situated next to the sofa. There is a \n" +
"large glass of lemonade and a few books on the table. There appears to be someone \n" +
"hiding behind the sofa. \n", 3)
