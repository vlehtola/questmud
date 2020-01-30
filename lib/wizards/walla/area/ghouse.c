#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster,monster2;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/gguard");
        move_object(monster, this_object());
    }
if (!monster2) {
        monster2 = clone_object("/wizards/walla/area/monsters/gguard2");
        move_object(monster2, this_object());
    }


THREE_EXIT("wizards/walla/area/ujar5", "west",
         "wizards/walla/area/tower5", "stairs",
         "wizards/walla/area/sewer", "sewer",
         "This is the guardhouse,",
         "This place is normally infested with guards, only today they are out fighting
with\n" +
         "Leb-Kamar out in the Assyrian desert. Only some guards are left \n", 3)
