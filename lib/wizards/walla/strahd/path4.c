#include "room.h"  
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(2);
    if (!monster) {
        monster = clone_object("/wizards/walla/strahd/monsters/wolf");
        move_object(monster, this_object());
    }
}
 
TWO_EXIT("wizards/walla/strahd/path3", "northeast",
         "wizards/walla/strahd/path5", "south",
         "A dark and misty path",
         "As you climb up higher on the path, you notice a strange mist starting to descend\n" +
         "on your mortal soul. The mist is very dense and it is getting harder to see now.\n" +
         "Also, it seems to get darker, the further you go from the crossing...\n", 2)
