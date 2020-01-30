#include "room.h" 
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/alchemist");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/area/ujar5", "east",
         "The alchemist shop",
         "This is a very important place in the Jerichan society\n" +
         "The ability to make gold is the skill known only to the alchemist himself.\n" +
         "But even he has not, to this day yet found the way to make that noble material, \n" +
         "even though he has tried for a good number of years. \n", 1)
