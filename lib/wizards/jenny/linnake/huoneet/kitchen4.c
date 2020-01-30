#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster4,monster5,monster6,monster7;
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
  if(!monster7) {
           monster7 = clone_object("wizards/jenny/linnake/mosut/chef.c");
           move_object(monster7, this_object());
        }
}

THREE_EXIT("/wizards/jenny/linnake/huoneet/kitchen3.c", "east",
           "/wizards/jenny/linnake/huoneet/kitchen2.c", "south",
           "/wizards/jenny/linnake/huoneet/kitchen1.c", "southeast",
           "You are at the northwest corner of the kitchen",
           "You are at the northwest corner of the kitchen, there is a big\n" +
           "chair where chef usually sits and a small stool for his legs.\n" +
           "This part is pretty clean because chef doesn't want anyone to\n" +
           "cook at this part. Here he just gives orders for maids and\n" +
           "controls that everything is under his control.\n", 1)
