#include "room.h" 
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(2);
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/bloodguard");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/area/testi/lebi", "west",
         "In a small room.",
         "This is a small and low room, and you can just and just stand straight here.\n" +
         "On the floor lies a pile of skulls and you can clearly see the outlines of a\n" +
         "pentagon drawn on the cold stone cobbled floor.\n", 2)

