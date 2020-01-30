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
 
TWO_EXIT("/wizards/morgoth/cannibal/room/path39", "south",
         "/wizards/morgoth/cannibal/room/path41", "west",
         "A path in cannibal village.",
         "You are on a rocky path in cannibal village.\n" + 
         "There is a cannibal huts west from path.\n", 1)
