#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/gguard");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/area/ujar-4", "south",
         
"Northern Gate",
         "You are under the walls, at the northern gate, to the north a pier\n" +
         "stretches out to the endless sea up ahead. \n", 3)
