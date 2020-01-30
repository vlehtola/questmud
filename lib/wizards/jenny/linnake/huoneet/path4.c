#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster,monster2;
extra_reset() {
        if(!monster) {
           monster = clone_object("wizards/jenny/linnake/mosut/hallguard.c");
           move_object(monster, this_object());
        }
  if(!monster2) {
           monster2 = clone_object("wizards/jenny/linnake/mosut/hallguard.c");
           move_object(monster2, this_object());
        }
}

THREE_EXIT("/wizards/jenny/linnake/huoneet/path3.c", "east",
           "/wizards/jenny/linnake/huoneet/path5.c", "west",
           "/wizards/jenny/linnake/huoneet/path7.c", "north",
           "You are walking in narrow hallway",
           "You are walking in narrow hallway that leads to east,west and north.\n" +
           "There is brown carpet on the floor and some paintings on the walls.\n" +
           "Torches at the wall are giving light to people. Some torches seem\n" +
           "to burn bit better than others but there is enough light so you can see.\n", 1)