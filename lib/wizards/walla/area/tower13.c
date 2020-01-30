#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/lebguard");
        move_object(monster, this_object());
    }
}

 
TWO_EXIT("wizards/walla/area/tower12", "down",
         "wizards/walla/area/tower14", "up",
         "mm, tassa vois olla viela toiset figut ",
         "You are standing in the spiral stairway to the minaret, the place from where\n" +
         "the priests call out praying time. \n", 3)



