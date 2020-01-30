#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/wayne/monsters/coharsky");
        move_object(monster, this_object());
    }
}
 
TWO_EXIT("wizards/walla/wayne/aurora54", "south",
        "wizards/walla/wayne/aurora53","north",
        "On Aurora avenue",
        "This is the main street of Aurora, Illinois. \n" +
         "South of here is Stan Nikita's doughnut parlor and Garth's house.\n", 3)
 
