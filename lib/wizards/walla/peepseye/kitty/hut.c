#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(1);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/peepseye/monsters/ferryman");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/peepseye/kitty/dock2", "west",
                

 "The ferrymans hut",
         "You are on the pier of OilOhnRock, and to inside the hut of the ferryman.\n" +
         "It looks like he is the man on the bunk. \n", 1)


