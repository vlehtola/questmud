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
 
FIVE_EXIT("wizards/walla/chessboard/27", "west",
         "wizards/walla/chessboard/18","north",
         "wizards/walla/chessboard/38", "south",
         "wizards/walla/chessboard/17", "northwest",
         "wizards/walla/chessboard/37","southwest",
         "On a white square in the chessboard",
         "You are on a white square of the chessboard.\n" +
         "This is the white pawn's place. \n", 3)
