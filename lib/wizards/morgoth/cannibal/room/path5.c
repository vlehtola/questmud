#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
 
object monsu;
int bucket_found;
 
extra_reset() {
    if (!monsu) {
        monsu = clone_object("/wizards/morgoth/cannibal/npc/cannibal.c");
        move_object(monsu, this_object());
    }
}
 
FOUR_EXIT("wizards/morgoth/cannibal/room/path4", "south",
         "wizards/morgoth/cannibal/room/path6", "north",
         "wizards/morgoth/cannibal/room/path23", "west",
         "wizards/morgoth/cannibal/room/path24", "east",
         "A crossing.",
         "You are on crossing.\n" + 
         "You can see many huts in village.\n", 1)
