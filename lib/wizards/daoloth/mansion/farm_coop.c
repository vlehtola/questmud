#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
     extra_reset();
ONE_EXIT("wizards/daoloth/mansion/farm_yard.c", "out",
         "Hen coop",
         "Uuh, what a mess. There are feathers and eggs everywhere.\n"
         "Stink awful because some of eggs are broken and looks like\n"
         "no one has cleaned this place for weeks.\n", 3)
extra_reset() {
items = allocate(90);
items[0] = "feathers";
items[1] = "fff";
}
