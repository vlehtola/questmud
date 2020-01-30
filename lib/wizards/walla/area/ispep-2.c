#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/citizen");
        move_object(monster, this_object());
    }
}
 
TWO_EXIT("wizards/walla/area/ispep-1", "east",
                       "wizards/walla/area/ispep-3", "west",       
          "On Ispep street ",
         "You are standing on the southern street in  Jericho.\n" +
         "High above is a vulture looking to find a corpse. \n", 3)

