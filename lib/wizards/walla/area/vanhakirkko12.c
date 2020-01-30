#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
 
object monster,monster2,monster3;
 
extra_reset() {
    items = allocate(2);
    items[0] = "stairway";
    items[1] = "All you can see is darkness";
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/monk");
        move_object(monster, this_object());
    }
    if (!monster2) {
        monster2 = clone_object("/wizards/walla/area/monsters/lebguard");
        move_object(monster2, this_object());
    }
if (!monster3) {
        monster3 = clone_object("/wizards/walla/area/monsters/lebguard");
        move_object(monster3, this_object());
    }
}
 
TWO_EXIT("wizards/walla/area/kirkko11","west",
"wizards/walla/area/tower11","up",
"In the mosquee.",
"This is the mosquee of Jericho, it's filled with candles hanging from the ceiling, and the smell\n" +
"of myrhh is clearly present. You can see the minaret from small windows, however, there seems to be two of them. \n", 3)     

