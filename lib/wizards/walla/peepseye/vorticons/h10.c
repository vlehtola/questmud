#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/peepseye/monsters/hellhound");
        move_object(monster, this_object());
    }
}
 
TWO_EXIT("wizards/walla/peepseye/vorticons/h9", "west",
         "wizards/walla/peepseye/vorticons/i10", "south",
         "In the maze",
         "In the maze.\n", 1)

