#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
     extra_reset();
TWO_EXIT("wizards/daoloth/mansion/farm_yard.c", "down",
         "wizards/daoloth/mansion/tree_room1.c", "up",
         "Tree",
         "You are standing on lowest branches of this huge tree. You see\n"
         "lot of strange movement on higher branches. Maybe you should\n"
         "go and look what's going on.\n"
         "That awful noise is coming from upper branches.\n", 3)
extra_reset() {
items = allocate(3);
items[0] = "branches";
items[1] = "Branches are so sturdy that even a giant could stand here";
}
