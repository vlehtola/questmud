#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
 
object monsu;
int bucket_found;
 
extra_reset() {
    if (!monsu) {
        monsu = clone_object("/wizards/morgoth/cannibal/npc/cook.c");
        move_object(monsu, this_object());
    }
}
 
ONE_EXIT("/wizards/morgoth/cannibal/room/path57.c", "out",
         "Cooking place.",
         "Cooking place.\n" +
         "This is cooking place, there is a HUGE pile of bones.\n", 3)
