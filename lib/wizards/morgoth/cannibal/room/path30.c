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
 
FOUR_EXIT("/wizards/morgoth/cannibal/room/hut11", "south",
         "/wizards/morgoth/cannibal/room/hut5", "north",
         "/wizards/morgoth/cannibal/room/path29", "west",
         "/wizards/morgoth/cannibal/room/path31", "east",
         "Path.",
         "You are on rocky path leading west and east.\n" +
         "There are cannibal huts both side of the path.\n", 3)