#include "room.h"
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/wight");
        move_object(monster, this_object());
    }
}
 
THREE_EXIT("wizards/walla/area/cem31", "south",
                  "wizards/walla/area/cem22", "east",
                  "wizards/walla/area/cem11", "north",
 "In the cemetary",
         "The northwestern part of this dark and bitter cemetary is covered with\n" +
         "a dense fog which covers the whole area upto about 4 feet.\n" +
         "All around you are tombstones with strange symbols carved on them. \n", 1)


