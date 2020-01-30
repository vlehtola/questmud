#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/chessboard/monsters/wbishop");
        move_object(monster, this_object());
    }
}
 
FIVE_EXIT("wizards/walla/chessboard/12", "west",
         "wizards/walla/chessboard/14","east",
         "wizards/walla/chessboard/23", "south",
         "wizards/walla/chessboard/22", "southwest",          
         "wizards/walla/chessboard/24","southeast",
         "On a white square in the chessboard",
         "You are on a white square of the chessboard.\n" +
         "This is the white bishop's place. \n", 3)

