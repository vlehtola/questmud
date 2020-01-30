
#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/peepseye/monsters/citizen");
        move_object(monster, this_object());
    }
}
 
TWO_EXIT("wizards/walla/peepseye/kitty/m2", "west",
         "wizards/walla/peepseye/kitty/m4", "east",
         "On Main Street, OilOhnRock",
         "As the Main Street gets bigger the crowd standing around here also grows.\n" +
         "People seem to be in a hurry because it seems like rain is on the way. \n", 3)
