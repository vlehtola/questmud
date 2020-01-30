#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/wayne/monsters/stan");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/wayne/aurora54", "out",
        "In Stan Nikita's Doughnut place",
        "This is the doughnut parlor of the town, and also a great get together place. \n" +
         "Here, the bests doughnuts of Aurora are made.\n", 3)
