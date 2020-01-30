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
 
TWO_EXIT("wizards/walla/area/estreet2", "north",
         "wizards/walla/area/estreet4", "south",
         "On Eastern street ",
         "You are standing on the eastern street in  Jericho.\n" +
         "High above is a vulture looking to find a corpse. \n", 3)
