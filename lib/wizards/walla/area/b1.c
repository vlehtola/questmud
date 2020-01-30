#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/bguard");
        move_object(monster, this_object());
    }
}
 
 
TWO_EXIT("wizards/walla/area/tower19", "in",
        "wizards/walla/area/b2", "continue",
         "soaring high up in the sky on a dangling ropebridge.",
         "You can see the whole town from here, the bazaar, the cemetary, the shops\n" +
         "and wait a minute, another tower \n", 3)
