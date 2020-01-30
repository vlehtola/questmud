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
 
TWO_EXIT("/wizards/morgoth/cannibal/room/path49", "west",
         "/wizards/morgoth/cannibal/room/path47", "east",
         "Path.",
         "You are on rocky path leading west and east.\n" +
         "There is nothing special.\n", 3)
