#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
     extra_reset();
THREE_EXIT("wizards/daoloth/mansion/farm_field1.c", "north",
           "wizards/daoloth/mansion/farm_field4.c", "west",
           "wizards/daoloth/mansion/farm_pond.c", "south",
           "Field",
           "Maybe some time ago this has been nice little field but\n"
           "now there is just growing weed everywhere. You see many\n"
           "nice animals jumping in the grass. You see a small pond\n"
           "in south.", 3)
extra_reset() {
items = allocate(4);
items[0] = "field";
items[1] = "Looks like no one hasn't take care of field for some time\n"
           "because there is growing weed everywhere";
items[2] = "pond";
items[3] = "There is a nice little pond in south. Maybe you should go\n"
           "and look it closer";
}
