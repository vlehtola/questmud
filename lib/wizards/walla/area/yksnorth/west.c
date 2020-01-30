#include "room.h" 
 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(0);
    if (!monster) {
        monster = clone_object("/wizards/walla/area/monsters/cube");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/area/yksnorth/lebway2", "east",
         "In a small and dark room",
         "This is a little room, just big enough for your party to stand here. You sense\n" +
         "the presence of something in the room, and you feel it coming closer.\n", 0)
         

