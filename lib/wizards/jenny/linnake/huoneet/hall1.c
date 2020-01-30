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

TWO_EXIT("/wizards/jenny/linnake/huoneet/hall4.c", "north",
           "/wizards/jenny/linnake/huoneet/entrance.c", "south",
           "You are walking in narrow hallway",
           "You are walking in narrow hallway that leads to north and south.\n" +
           "There is brown carpet on the floor and some paintings on the walls.\n" +
           "Torches at the wall are giving light to people. Some torches seem\n" +
           "to burn bit better than others but there is enough light so you can see.\n", 1)
