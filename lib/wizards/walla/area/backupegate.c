#include "room.h" 
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/gguard");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/area/estreet1", "west",
         "The drawbridge",
         "You are now on a the drawbridge to Jericho. It is has been built\n" +
         "to prevent any enemies getting into the city.\n" +
         "To the north you see the large fortifications once built \n" +
         "by the Leb-Kamar and his men. \n", 3)
