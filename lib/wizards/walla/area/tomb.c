#include "room.h" 
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(1);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/skeleton");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/area/cem41", "out",
                  "This is a regular tomb.",
         "Someone seems to in it.\n", 1)
