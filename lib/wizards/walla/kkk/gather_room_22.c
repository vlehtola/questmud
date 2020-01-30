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
 
FIVE_EXIT("wizards/walla/kkk/gather_room_32", "south",
         "wizards/walla/kkk/gather_room_21", "west",
         "wizards/walla/kkk/gather_room_31", "southwest",
         "wizards/walla/kkk/gather_room_33", "southeast",
         "wizards/walla/kkk/gather_room_23", "east",
         "In the middle of the big ressembly room",
         "This is the centre of the great big hall. From all sides you can hear cheering, and it seems\n" +
         "like all the people are waiting for something special to happen. \n", 3)

