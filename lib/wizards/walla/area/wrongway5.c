#include "room.h"
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(1);

 EIGHT_EXIT("wizards/walla/area/wrongway1", "northeast",
     "wizards/walla/area/wrongway6", "down",
     "wizards/walla/area/wrongway2", "up",
    "wizards/walla/area/wrongway6", "west",
    "wizards/walla/area/wrongway4", "south",
    "wizards/walla/area/wrongway3", "northwest",
   "wizards/walla/area/maze11", "southeast",
   "wizards/walla/area/wrongway2", "southwest",   
        
 "In the maze ",
         "You are in the maze \n" +
         "evrything looks alike. \n", 1)
