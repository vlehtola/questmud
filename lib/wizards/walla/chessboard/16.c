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
 
FIVE_EXIT("wizards/walla/chessboard/15", "west",
         "wizards/walla/chessboard/17","east",
         "wizards/walla/chessboard/26", "south",
         "wizards/walla/chessboard/25", "southwest",          
         "wizards/walla/chessboard/27","southeast",
         "On a black square in the chessboard",
         "You are on a black square of the chessboard.\n" +
         "This is the white bishop's place. \n", 3)

