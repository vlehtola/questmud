#include "room.h" 
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/lguard);
        move_object(monster, this_object());
    }
}
 
TWO_EXIT("wizards/walla/area/lebway1", "north",
         "wizards/walla/area/cem23", "up",
         Under the cemetary ",
         "You discover a secret tunnel under the grave, that you just kicked\n" +
         "open. To the north, you notice a covered trail, it seems like some \n" +
         "attempt to cover up its existance has been made. \n" +
         "You feel nervous, and think the walls are beginning to fall on to you. \n", 3)

