#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;
extra_reset() {
        if(!monster) {
           monster = clone_object("wizards/jenny/linnake/mosut/jail_guard.c");
           move_object(monster, this_object());
        }
}

EIGHT_EXIT("/wizards/jenny/linnake/huoneet/prison13.c", "west",
           "/wizards/jenny/linnake/huoneet/prison18.c", "northwest",
           "/wizards/jenny/linnake/huoneet/prison17.c", "north",
           "/wizards/jenny/linnake/huoneet/prison16.c", "northeast",
           "/wizards/jenny/linnake/huoneet/prison15.c", "east",
           "/wizards/jenny/linnake/huoneet/prison10.c", "southeast",
           "/wizards/jenny/linnake/huoneet/prison11.c", "south",
           "/wizards/jenny/linnake/huoneet/prison12.c", "southwest",
           "You are walking in a prison complex",
           "You are walking in a prison complex and you see guards dragging some\n" +
           "dead prisoner away from a cell. Some rats are wildly running on the\n" +
           "floor. All cell doors are made of iron and they seem to be\n" +
           "very good quality.\n", 1)
