#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
     extra_reset();
ONE_EXIT("wizards/daoloth/mansion/tree_room1.c", "west",
         "Tree",
         "You are standing on east side of the tree. You see a lot\n"
         "of squirrels running around tree and eating acorns.\n"
         "Some squirrels are carrying acorns to the hole what is in\n"
         "the middle of the trunk. You see long sturdy branches going\n"
         "to every directions.\n"
         "That noise is making you crazy!\n", 3)
extra_reset() {
items = allocate(10);
items[0] = "hole";
items[1] = "Many squirrels are carrying acorns to that man-sized hole\n"
           "You wonder what kind of secret it's hiding. Maybe you\n"
           "should go and look it closer";
}
