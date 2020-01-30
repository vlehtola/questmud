#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/chessboard/monsters/wtower");
        move_object(monster, this_object());
    }
}
 
THREE_EXIT("wizards/walla/chessboard/12", "east",
         "wizards/walla/chessboard/22","southeast",
         "wizards/walla/chessboard/21", "south",
         "On a white square in the chessboard",
         "You are on a white square of the chessboard.\n" +
         "This is the white tower's place. \n", 3)
