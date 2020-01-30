#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/wayne/monsters/punk");
        move_object(monster, this_object());
    }
}
 
THREE_EXIT("wizards/walla/wayne/waynehouse", "in",
        "wizards/walla/wayne/aurora45","west",
        "wizards/walla/wayne/aurora54","north",
        "On Aurora avenue",
        "This is the main street of Aurora, Illinois. \n" +
         "South of here is Wayne's house. To the other directions, there are other houses.\n", 3)


