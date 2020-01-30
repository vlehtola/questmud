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

TWO_EXIT("/wizards/jenny/linnake/huoneet/kitchen1.c", "north",
           "/wizards/jenny/linnake/huoneet/path24.c", "west",
           "You are walking in narrow hallway",
           "You are walking in narrow hallway that leads to west and north.\n" +
           "There is brown carpet on the floor and some paintings on the walls.\n" +
           "At north you can see a kitchen. Some maids are working with chef and\n" +
           "they seem to be very busy with those orders they get from people of Roxen.\n", 1)
