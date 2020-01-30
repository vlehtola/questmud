#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/lguard");
        move_object(monster, this_object());
    }
}

FIVE_EXIT("wizards/walla/workroom", "north",
         "wizards/walla/area/cem23", "up",
         "wizards/walla/workroom", "west",
         "wizards/walla/workroom","east",
         "wizards/walla/workroom", south",
         "On Ujar street ",
         "You are standing on Ujar street, the main street of Jericho .\n" +
         "To whe west is the old and abandonned smithy's shop.\n" +
         "To the east is the entrance to the bazaar. \n" +
         "Many people are running around here busy and nervous. \n", 3)
