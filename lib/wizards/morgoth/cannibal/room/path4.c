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
 
FOUR_EXIT("wizards/morgoth/cannibal/room/path3", "south",
         "wizards/morgoth/cannibal/room/path5", "north",
         "wizards/morgoth/cannibal/room/path23", "northwest",
         "wizards/morgoth/cannibal/room/path24", "northeast",
         "A entrance to cannibal village.",
         "You are standing on entrance of the cannibal village.\n" + 
         "You can hear strange mumbling coming from village.\n", 1)
