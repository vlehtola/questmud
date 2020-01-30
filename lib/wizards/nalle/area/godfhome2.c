#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "fountain";
    items[1] = "It's a fountain made of marble with non-potable looking water in it.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/dog");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/tie12","north",
"wizards/nalle/area/billeth","south",
"The garden of the Billeth residence",
"This is the beautiful garden of Mr. Billeth's residence. There is a small fountain\n" +
"in the middle of the lawn and a small paved path leads to his house. You marvel\n" +
"at the size of the house and hope that one day you will also be able to purchase\n" +
"a house from the Godfrey road. You notice a large doghouse under a maple tree. \n", 3)

