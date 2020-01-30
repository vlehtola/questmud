#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/dl/monsters/vakiogd");
        move_object(monster, this_object());
    }
}
FOUR_EXIT("wizards/walla/dl/rooms/xaktsaroth/gd3", "west",
"wizards/walla/dl/rooms/xaktsaroth/gdhome4n", "north",
"wizards/walla/dl/rooms/xaktsaroth/gdhome4s", "south",
        "wizards/walla/dl/rooms/xaktsaroth/gd5", "east",
        "The Gully Dwarf camp",
         "This place smells like rotten pigs and laughter and tools are to\n" +
 "be heard further on. There appears to be housing on either side.\n", 3)

