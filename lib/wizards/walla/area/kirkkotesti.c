#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster,monster2,monster3;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/monk");
        move_object(monster, this_object());
    }
 

if (!monster2) {
        monster2 = clone_object("/wizards/walla/area/monsters/leb-guard");
        move_object(monster2, this_object());
    }

 
    if (!monster3) {
        monster3 = clone_object("/wizards/walla/area/monsters/leb-guard");
        move_object(monster3, this_object());
    }
}
 
 
 
 
 
THREE_EXIT("wizards/walla/area/kirkko13", "east",
         "wizards/walla/area/kirkko11", "west",
         "wizards/walla/area/tower11", "up",
"You are in the mosquee at the bottom of a spiral staircase",
         "This is the mosquee of Jericho, it's filled with candles hanging from the ceiling, and the smell\n" +
         "of myrhh is clearly present. You can see the minaret from small windows, however, there seems to be two of them. \n", 3)
