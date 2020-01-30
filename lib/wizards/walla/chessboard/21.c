#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/chessboard/monsters/wpawn");
        move_object(monster, this_object());
    }
}
 
FIVE_EXIT("wizards/walla/chessboard/22", "east",
         "wizards/walla/chessboard/11","north",
         "wizards/walla/chessboard/31", "south",
         "wizards/walla/chessboard/12", "northeast",
         "wizards/walla/chessboard/32","southeast",
         "On a black square in the chessboard",
         "You are on a black square of the chessboard.\n" +
         "This is the white pawn's place. \n", 3)
