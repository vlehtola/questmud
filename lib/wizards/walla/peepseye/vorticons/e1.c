#include "room.h" 
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(1);
 
TWO_EXIT("wizards/walla/peepseye/vorticons/d1", "north",
         "wizards/walla/peepseye/vorticons/f1", "south",
         "In the maze",
         "In the maze. \n", 1)



