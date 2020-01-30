#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
ONE_EXIT("wizards/daoloth/mansion/tree_hole2.c", "down",
         "Inside tree",
         "This seems to be somekind of lookout place. There are holes\n"
         "all over the walls and many squirrels are standing near holes\n"
         "and keeping watch. You wonder why you're still alive because\n"
         "this is a great place to see all intruders. Ladders are going\n"
        "down. You don't know how much longer you can stand this noise.\n", 3)
extra_reset() {
items = allocate(6);
items[0] = "ladders";
items[1] = "Ladders are very sturdy and with good luck even a giant could\n"
           "use them. Ladders are going up and down.\n"
           "You wonder why squirrels would need ladders";
items[2] = "squirrels";
items[3] = "Squirrels are standing near holes and keeping watch";
items[4] = "holes";
items[5] = "You can clearly see the house and the yard from these. This is\n"
           "an excellent place for keeping watch";
}
