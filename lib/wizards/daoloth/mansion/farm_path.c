#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
     extra_reset();
TWO_EXIT("wizards/daoloth/mansion/farm_yard.c", "northeast",
         "wizards/daoloth/mansion/farm_field1.c", "south",
         "Small path",
         "You're walking on a small path. In south you see a small field\n"
         "and in northeast you see small farm. Hill is in north from\n"
         "here. There is lot of trees near the path and you can hear\n"
         "some bird singing.\n", 3)
extra_reset() {
items = allocate (6);
items[0] = "path";
items[1] = "Looks like no one hasn't use the path for some time. It's very\n"
           "strange because usually farmers takes good care of fields.\n";
items[2] = "field";
items[3] = "Looks like no one hasn't take care of field for some time.\n";
items[4] = "farm";
items[5] = "You see a nice little farm in northeast. There is a small red\n"
           "painted house near that big hill. You see small yard in\n"
           "front of the house. There is a hen coop in northwest corner\n"
           "of yard. In the middle of yard there is huge old oak tree\n"
           "and a well under it";
}
