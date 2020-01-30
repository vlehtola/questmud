#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
 
object monsu;
int bucket_found;
 
extra_reset() {
    if (!monsu) {
        monsu = clone_object("/wizards/morgoth/cannibal/npc/king.c");
        move_object(monsu, this_object());
    }
}
 
ONE_EXIT("/wizards/morgoth/cannibal/room/path10.c", "out",
         "Kings hut.",
         "This is kings hut.\n" +
         "This place is decorated with human skulls.\n", 3)
