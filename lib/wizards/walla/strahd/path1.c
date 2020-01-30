#include "room.h" 
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(1);
    if (!monster) {
        monster = clone_object("/wizards/walla/strahd/monsters/wolf");
        move_object(monster, this_object());
    }
}
 
TWO_EXIT("wizards/walla/strahd/path2", "south",
         "wizards/walla/strahd/hut", "southwest",
         "On the path to the castle",
         "You are on the path leading to the castle Strahd. The air is getting colder the higher\n" +
         "you are. Up north you see a magnificent castle, which you can't reach because the \n" +
         "the drawbridge is not down to welcome you. To your back left side is a small hut,\n" +
         "from which you can see light peering through the windowloops.\n", 1)
