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
 
FOUR_EXIT("wizards/walla/kkk/gather_room_13", "north",
         "wizards/walla/kkk/gather_room_22", "west",
         "wizards/walla/kkk/gather_room_32", "southwest",
         "wizards/walla/kkk/gather_room_33", "south",
         "In the eastern side of the big ressembly room",
         "This is the a place in the great big hall. From here you can see very well the stage, but yet\n" +
         "it seems so unreachable. Maybe because it's so far away. \n", 3)

