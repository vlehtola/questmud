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

TWO_EXIT("/wizards/jenny/linnake/huoneet/path5.c", "east",
           "/wizards/jenny/linnake/huoneet/basement2.c", "down",
           "You are at top of the stairs",
           "You are at top of the stairs that lead to the basement.\n" +
           "There are some torches burning near you and you smell the rotten\n" +
           "corpses of rats somewhere here. A weird noise is coming from downstairs,\n" +
           "it seems like someone or something is hitting chains against walls or something.\n", 1)
           
