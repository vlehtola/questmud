#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/ravenloft/areas/stranger/stranger");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/workroom", "pois",
        "A campfire in the middle of nowhere",
         "A man sits here.\n", 3)
