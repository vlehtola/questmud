#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/chessboard/monsters/wqueen");
        move_object(monster, this_object());
    }
}
 
FIVE_EXIT("wizards/walla/chessboard/13", "west",
         "wizards/walla/chessboard/15","east",
         "wizards/walla/chessboard/24", "south",
         "wizards/walla/chessboard/23", "southwest",
         "wizards/walla/chessboard/25","southeast",
         "On a black square in the chessboard",
         "You are on a black square of the chessboard.\n" +
         "This is the white queen's place. \n", 3)
