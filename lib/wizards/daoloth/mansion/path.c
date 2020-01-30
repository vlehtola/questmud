#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
     extra_reset();
TWO_EXIT("wizards/daoloth/mansion/mansion_front.c", "north",
         "wizards/daoloth/mansion/crossing.c", "south",
         "Path",
         "There are lot of trees near path and you can hear some bird\n"
         "singing. Path is going towards old mansion at north.\n"
         "You can see crossing far at south.\n", 3)
extra_reset() {
items = allocate(90);
items[0] = "path";
items[1] = "No one hasn't use this for long time";
items[2] = "mansion";
items[3] = "You see old dark mansion at north. You can clearly see from\n"
           "here that it's not in good condition anymore";
}
