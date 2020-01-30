#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
     extra_reset();
THREE_EXIT("wizards/daoloth/mansion/path.c", "north",
           "wizards/daoloth/mansion/path2.c", "west",
           "wizards/daoloth/mansion/path3.c", "south",
           "Crossing",
        "You stand at crossing. There are lot of trees around this place.\n"
           "You notice that paths going west and south have been used more\n"
           "than north path. You also see old sign standing here.\n", 3)
extra_reset() {
items = allocate(90);
items[0] = "sign";
items[1] = "North      Mansion\n"
           "West       Farm\n"
           "South      Duranghom";
}
