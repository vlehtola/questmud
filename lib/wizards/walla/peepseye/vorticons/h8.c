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
 
THREE_EXIT("wizards/walla/peepseye/vorticons/h9", "east",
         "wizards/walla/peepseye/vorticons/g8", "north",
         "wizards/walla/peepseye/vorticons/i8", "south",
         "In the maze",
         "In the maze.\n", 1)
