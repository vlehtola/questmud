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
 
TWO_EXIT("/wizards/morgoth/cannibal/room/path28", "west",
         "/wizards/morgoth/cannibal/room/path30", "east",
         "A path in cannibal village.",
         "You are on a rocky path in cannibal village.\n" + 
         "There are cannibal huts both side of the path.\n", 3)
