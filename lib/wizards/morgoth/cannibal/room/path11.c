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
 
TWO_EXIT("/wizards/morgoth/cannibal/room/path12", "east",
         "/wizards/morgoth/cannibal/room/path69", "north",
         "A path in cannibal village.",
         "You are on a rocky path in cannibal village.\n" + 
         "There is a cannibal huts east from the path.\n", 1)
