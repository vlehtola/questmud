#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster4,monster5,monster6;
extra_reset() {
        if(!monster4) {
           monster4 = clone_object("wizards/jenny/linnake/mosut/maid.c");
           move_object(monster4, this_object());
        }
  if(!monster5) {
           monster5 = clone_object("wizards/jenny/linnake/mosut/maid.c");
           move_object(monster5, this_object());
        }  
  if(!monster6) {
           monster6 = clone_object("wizards/jenny/linnake/mosut/maid.c");
           move_object(monster6, this_object());
        } 

}

FOUR_EXIT("/wizards/jenny/linnake/huoneet/kitchen4.c", "west",
           "/wizards/jenny/linnake/huoneet/storage1.c", "east",
           "/wizards/jenny/linnake/huoneet/kitchen2.c", "southwest",
           "/wizards/jenny/linnake/huoneet/kitchen1.c", "south",
           "You are at the northeast corner of the kitchen",
           "You are at the northeast corner of the kitchen, next to you is a\n" +
           "big pot full of steaming soup, it smells delicious and you wish\n" +
           "you could taste it, but chef might not want everyone to taste his\n" +
           "dishes. At east you see a small storage room filled with meat, fish\n" +
           "and other food supplies.\n", 1)
