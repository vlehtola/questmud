#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/wayne/monsters/mrwong");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/wayne/waynehouse", "down",
        "In the attic of Wayne's house",
         "The elevator behind you occupies more than half the space here. Otherwise the \n" +
         "place looks neat.\n", 3)

