#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
     extra_reset();
TWO_EXIT("wizards/daoloth/mansion/crossing.c", "east",
         "wizards/daoloth/mansion/path4.c", "southwest",
         "Path",
         "There is lot of trees near path and you can hear some bird\n"
         "singing. You see a hill far at southwest and a farm near it.\n"
         "You see a crossing far at east.\n", 3)
extra_reset() {
items = allocate(90);
items[0] = "hill";
items[1] = "You have never seen that kind of hill in forests\n";
           "It's much larger than usually hills are forests\n";
items[2] = "farm";
items[3] = "You're still too far to see any details";
}
