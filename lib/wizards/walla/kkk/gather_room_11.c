#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/kkk/monsters/initiate");
        move_object(monster, this_object());
    }
}
 
ONE_EXIT("wizards/walla/kkk/gather_room_21", "south",
         
         "In the northwestern corner of the big ressembly room",
         "This is the a place in the great big hall. From here you can see very well the stage, but yet\n" +
         "it seems so unreachable. \n", 3)

