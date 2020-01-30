#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
 
object monsu;
int bucket_found;
 
extra_reset() {
    if (!monsu) {
        monsu = clone_object("/wizards/morgoth/cannibal/npc/guard.c");
        move_object(monsu, this_object());
    }
}
 
FOUR_EXIT("wizards/morgoth/cannibal/room/path9", "south",
         "wizards/morgoth/cannibal/room/khut", "hut",
         "wizards/morgoth/cannibal/room/path53", "southwest",
         "wizards/morgoth/cannibal/room/path52", "southeast",
         "A path in cannibal village.",
         "You are on a rocky path in cannibal village.\n" + 
         "North from here is kings hut.\n", 3)
