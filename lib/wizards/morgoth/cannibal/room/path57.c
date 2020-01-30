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
 
THREE_EXIT("/wizards/morgoth/cannibal/room/chut", "north",
         "/wizards/morgoth/cannibal/room/path58", "west",
         "/wizards/morgoth/cannibal/room/path56", "east",
         "Path.",
         "You are on rocky path leading west and east.\n" +
         "There is a chitchen hut north from here.\n", 3)
