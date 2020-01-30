#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/bguard3");
        move_object(monster, this_object());
    }
}

 
TWO_EXIT("wizards/walla/area/tower28", "down",
        "wizards/walla/area/b2", "out", 
        "mm, tassa vois olla viela toiset figut ",
         "You are standing on top of the spiral stairway. You see a ropebridge from the hole  \n" +
         "in the wall. I hope it holds your weight. \n", 3)

