#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/dl/monsters/poddrac1");
        move_object(monster, this_object());
    }
}
TWO_EXIT("wizards/walla/dl/rooms/xaktsaroth/pathsofdead4", "east",
"wizards/walla/dl/rooms/xaktsaroth/pathsofdead2","south",
"The paths of the Dead",
        "This room gives you a really creepy feeling. The fact that you can't see a thing\n" +
        "doesn't make things any less uncomfortable\n", 0)
 

