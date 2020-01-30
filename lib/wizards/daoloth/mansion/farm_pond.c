#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
     extra_reset();
ONE_EXIT("wizards/daoloth/mansion/farm_field2.c", "north",
         "Pond",
         "You see a nice little pond. Many maple trees surround this\n"
         "this place. You hear nice bird singing from trees\n"
         "There is a iron bucket near pond.\n", 3)
extra_reset() {
items = allocate(4);
items[0] = "pond";
items[1] = "There is nice clear water in pond. It seems to be clean\n"
           "enough for drinking";
items[2] = "bucket";
items[3] = "Maybe someone has carried water in it. But there is a well\n"
           "near the house so why someone would like to carry water\n"
           "from here";
}
