#include "room.h"
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/zombie2");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/area/guardhouse", "up",
                  "These are the sewers",
         "A foul stench covers this place\n", 1)
