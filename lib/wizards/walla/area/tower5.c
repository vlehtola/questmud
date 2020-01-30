#include "room.h" 
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(1);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/mage");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/walla/area/guardhouse", "down",
         "Prison tower",
"You are in the city's prison tower. The stone walls are cold and hard.\n"+
"There is a bed in the corner of this small room. A tiny barred window\n"+
"yields little light.\n", 1)
