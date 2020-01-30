#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster,monster2,monster3;
extra_reset() {
        if(!monster) {
           monster = clone_object("wizards/jenny/linnake/mosut/chambermaidc.c");
           move_object(monster, this_object());
        }
       if(!monster2) {
           monster2 = clone_object("wizards/jenny/linnake/mosut/chambermaidb.c");
           move_object(monster2, this_object());
        } 
      if(!monster3) {
           monster3 = clone_object("wizards/jenny/linnake/mosut/chambermaid.c");
           move_object(monster3, this_object());
        } 
}

EIGHT_EXIT("/wizards/jenny/linnake/huoneet/hall10.c", "west",
           "/wizards/jenny/linnake/huoneet/hall13.c", "northwest",
           "/wizards/jenny/linnake/huoneet/hall14.c", "north",
           "/wizards/jenny/linnake/huoneet/hall15.c", "northeast",
           "/wizards/jenny/linnake/huoneet/hall8.c", "east",
           "/wizards/jenny/linnake/huoneet/hall5.c", "southeast",
           "/wizards/jenny/linnake/huoneet/hall4.c", "south",
           "/wizards/jenny/linnake/huoneet/hall3.c", "southwest",
           "You are walking in a massive hall",
           "You are walking in a massive hall, There are huge pillars all\n" +
           "around you and some chandeliers are hanging from the ceiling.\n" +
           "A few windows have been placed high, near the ceiling and \n" +
           "a loud noise is coming from upstairs.\n", 1)
