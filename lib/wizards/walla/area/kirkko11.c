#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/monk");
        move_object(monster, this_object());
    }
}
 
TWO_EXIT("wizards/walla/area/kirkko12", "east",
         "wizards/walla/area/ujar-2", "west",
         
"You are in the mosquee ",
         "This is the mosquee of Jericho, it's filled with candles hanging from the ceiling, and the smell\n" +
         "of myrhh is clearly present. You can see the minaret from small windows, however, there seems to be two of them. \n", 3)
