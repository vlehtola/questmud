#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
 
object monsu;
int bucket_found;
 
extra_reset() {
    if (!monsu) {
        monsu = clone_object("/wizards/morgoth/can.c");
        move_object(monsu, this_object());
    }
 
ONE_EXIT("world/city/inn", "inn",
"Example room",
"This is an example room. There is something in the water. There is a 
sign.\n", 3)
 
 
 
