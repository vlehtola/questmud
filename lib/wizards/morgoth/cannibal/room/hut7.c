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
 
ONE_EXIT("/wizards/morgoth/cannibal/room/path13.c", "out",
         "Hut.",
         "This is normal cannibal hut.\n" +
         "This place is really messy.\n", 1)
