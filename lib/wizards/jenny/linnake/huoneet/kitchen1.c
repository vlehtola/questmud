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

FOUR_EXIT("/wizards/jenny/linnake/huoneet/path25.c", "south",
           "/wizards/jenny/linnake/huoneet/kitchen2.c", "west",
           "/wizards/jenny/linnake/huoneet/kitchen4.c", "northwest",
           "/wizards/jenny/linnake/huoneet/kitchen3.c", "north",
           "You are at the entrance to the kitchen",
           "You are at the entrance to the kitchen, at west you see large kitchen\n" +
           "sink and many bags of potatoes, carrots and other vegetables.\n" +
           "In north there is a big pot full of steaming soup and on the walls there\n" +
           "are knives and other kitchen stuff. In northwest part of kitchen you see\n" +
           "place where chef usually watches maids and orders them to do the dirty work.\n", 1)
