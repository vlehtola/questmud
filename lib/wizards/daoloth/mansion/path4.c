#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
     extra_reset();
TWO_EXIT("wizards/daoloth/mansion/farm_yard.c", "west",
         "wizards/daoloth/mansion/path2.c", "northeast",
         "Path",
         "There is lot of trees near path and you can hear some bird\n"
         "singing. You see a hill at west and a nice little farm "
         "near it.\n", 3)
extra_reset() {
items = allocate(90);
items[0] = "hill";
items[1] = "You have never seen that kind of hill in forests\n"
           "It's much larger than usually hills are forests";
items[2] = "farm";
items[3] = "You see a nice little farm at west. There is a small red\n"
           "painted house near that big hill. You see small yard in\n"
           "front of the house. There is a hen-coop in northwest corner\n"
           "of yard. In the middle of yard there is huge old oak tree\n"
           "and a well under it. You see small path going southwest\n"
           "from yard";
}
