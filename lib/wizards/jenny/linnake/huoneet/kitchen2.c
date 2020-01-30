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

THREE_EXIT("/wizards/jenny/linnake/huoneet/kitchen1.c", "east",
           "/wizards/jenny/linnake/huoneet/kitchen4.c", "north",
           "/wizards/jenny/linnake/huoneet/kitchen3.c", "northeast",
           "You are at the southwest corner of the kitchen",
           "You are at the southwest corner of the kitchen, there is a big\n" +
           "kitchen sink in the corner and many bags of potatoes, carrots and\n" +
           "other vegetables lying near you. When you breath the air you can\n" +
           "smell divine flavours of excellent food everywhere around you.\n" +
           "Kitchen looks pretty messy, but still somehow it feels like home\n", 1)
