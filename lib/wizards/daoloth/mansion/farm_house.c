#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
     extra_reset();
TWO_EXIT("wizards/daoloth/mansion/farm_house1.c", "west",
         "wizards/daoloth/mansion/farm_yard.c", "out",
         "House",
         "You wonder what kind of pig can live in here. You see dust and\n"
         "carbage everywhere. This room looks like a kitchen.\n"
       "You see small table in left corner and a stove in right corner.\n", 3)
extra_reset() {
items = allocate (20);
items[0] = "table";
items[1] = "You see some broken eggs and dozen empty bean cans";
items[2] = "stove";
items[3] = "You see a small pot on stove";
items[4] = "pot";
items[5] = "Looks like someone has ate here few minutes ago because there\n"
           "is some warm beans in pot";
items[6] = "carbage";
items[7] = "You see lot empty bean cans all over the house";
}
