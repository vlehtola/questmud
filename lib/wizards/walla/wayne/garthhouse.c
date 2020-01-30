#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/wayne/monsters/gdog");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/wayne/aurora54", "out",
        "In Garth's house",
        "This is Garth's place, there is a set of drums in the left corner and a bed in the other.\n" +
        "Garth's dog guards here.\n", 3)

