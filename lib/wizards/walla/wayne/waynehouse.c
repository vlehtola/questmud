#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/wayne/monsters/maid");
        move_object(monster, this_object());
    }
}
 
THREE_EXIT("wizards/walla/wayne/aurora55", "out",
         "wizards/walla/wayne/wayneup", "elevator",
         "wizards/walla/wayne/waynedown", "basement",
"The house of Wayne Campbell",
         "This is Wayne's house. Wayne doesn't seem to be here right now,\n" +
         "he probably partys with his pals somewhere. \n", 3)
