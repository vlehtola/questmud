#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/worker");
        move_object(monster, this_object());
    }
}
 
TWO_EXIT("wizards/walla/area/ujar1", "south",
         "wizards/walla/area/ispep1", "east",
         "Central Square",
         "You are in the, what is about to become the central square of the city.\n" +
         "Workers are making roads to different locations of the town from here. \n", 3)
