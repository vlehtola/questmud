#include "room.h" 
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        set_not_out(1);
 
 EIGHT_EXIT("wizards/walla/area/wrongway3", "northeast",
     "wizards/walla/area/lebroute5", "down",
     "wizards/walla/area/wrongway1", "up",
    "wizards/walla/area/wrongway2", "down",
    "wizards/walla/area/wrongway4", "south",
    "wizards/walla/area/wrongway4", "northwest",
   "wizards/walla/area/wrongway6", "north",
   "wizards/walla/area/wrongway5", "southwest",
 
  "In the maze ",
         "You are in the maze \n" +
  "Torches illuminate the path. \n", 2)

