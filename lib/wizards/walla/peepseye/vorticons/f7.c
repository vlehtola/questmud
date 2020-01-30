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
 
TWO_EXIT("wizards/walla/peepseye/vorticons/e7", "north",
         "wizards/walla/peepseye/vorticons/g7", "south",
         "In the maze",
         "In the maze.\n", 1)





















