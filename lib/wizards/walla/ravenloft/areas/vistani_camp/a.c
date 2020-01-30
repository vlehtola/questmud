#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/ravenloft/areas/vistani_camp/monsters/gypsieman");
        move_object(monster, this_object());
    }
}
 
TWO_EXIT("wizards/walla/ravenloft/vistani_camp/b", "north",
         "wizards/walla/ravenloft/outworld/vistani_entrance", "south",
         "At a bonfire in a vistani camp",
         "To the north you can hear music of a strange kind, such as you have not heard before.\n" +
         "It makes you curious, but still, it makes you very restless. \n", 3)
