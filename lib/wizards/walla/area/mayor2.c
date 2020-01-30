
#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/mayor");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/area/mayor", "west",
         "Inside the mayor's office",
         "You are inside the newly build mayor's office. The walls are made\n" +
         "of newly cut chalkstone and lights flicker in all the corners. \n", 3)
