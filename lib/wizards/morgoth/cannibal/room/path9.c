#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
 
object monsu;
int bucket_found;
 
extra_reset() {
    if (!monsu) {
        monsu = clone_object("/wizards/morgoth/cannibal/npc/lcannibal.c");
        move_object(monsu, this_object());
    }
}
 
FOUR_EXIT("wizards/morgoth/cannibal/room/path8", "south",
         "wizards/morgoth/cannibal/room/path10", "north",
         "wizards/morgoth/cannibal/room/path53", "west",
         "wizards/morgoth/cannibal/room/path52", "east",
         "A crossing.",
         "You are on crossing.\n" + 
         "North from here is a king's hut.\n", 1)
