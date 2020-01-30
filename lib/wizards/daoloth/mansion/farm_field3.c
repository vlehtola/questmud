#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
     extra_reset();
TWO_EXIT("wizards/daoloth/mansion/farm_field1.c", "east",
         "wizards/daoloth/mansion/farm_field4.c", "south",
         "Field",
         "Maybe some time ago this has been nice little field but\n"
         "now there is just growing weed everywhere. You see many\n"
         "nice animals jumping in the grass.\n", 3)
extra_reset() {
items = allocate(4);
items[0] = "field";
items[1] = "Looks like no one hasn't take care of field for some time\n"
           "because there is growing weed everywhere";
}
