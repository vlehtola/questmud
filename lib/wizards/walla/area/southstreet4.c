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
 
TWO_EXIT("wizards/walla/area/estreet4", "north",
         "wizards/walla/area/southstreet3", "west",
         "On Ujar street ",
         "You are standing on the southern street in  Jericho.\n" +
         "High above is a vulture looking to find a corpse. \n", 3)
