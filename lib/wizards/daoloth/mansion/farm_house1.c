#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
     extra_reset();
ONE_EXIT("wizards/daoloth/mansion/farm_house.c", "east",
         "Bedroom",
         "This looks like somekind of bedroom. There is lots of dust and\n"
         "dirt all over room.You see a small and dirty bed in right\n"
         "corner. There's a small closet in left corner.\n", 3)
extra_reset() {
items = allocate (10);
items[0] = "bed";
items[1] = "Bed seems to be very dirty";
items[2] = "closet";
items[3] = "When you open closet you see some mining equipment there.\n"
           "You have no idea why some farmer would need those";
}
