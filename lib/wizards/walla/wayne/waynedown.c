#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/wayne/monsters/nick");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/wayne/waynehouse", "up",
        "In the basement of Wayne's house",
         "Here is the place that Wayne's World is filmed.\n" +
         "The set is huge.\n", 3)

