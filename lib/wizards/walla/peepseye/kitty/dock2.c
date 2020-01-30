#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/peepseye/monsters/gull");
        move_object(monster, this_object());
    }
}
 
THREE_EXIT("wizards/walla/peepseye/kitty/dock1", "south",
         "wizards/walla/peepseye/kitty/dock", "north",
         "wizards/walla/peepseye/kitty/hut", "east",
 
 "On Ocean Alley in OilOhnRock",
         "You are on the pier of OilOhnRock, and to the east is the hut of the ferryman.\n" +
         "Up ahead it seems like a boat or a ship could dock here. \n", 3)
