#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
 
object monster;
 
extra_reset() {
    set_not_out(3);
 
    if (!monster) {
        monster = clone_object("/wizards/walla/chessboard/monsters/bpawn");
        move_object(monster, this_object());
    }
}
 
EIGHT_EXIT("wizards/walla/chessboard/78", "east",
         "wizards/walla/chessboard/67","north",
         "wizards/walla/chessboard/87", "south",
         "wizards/walla/chessboard/68", "northeast",
         "wizards/walla/chessboard/88","southeast",
         "wizards/walla/chessboard/76","west",         
         "wizards/walla/chessboard/66","northwest",
         "wizards/walla/chessboard/68","northeast",
"On a white square in the chessboard",
         "You are on a white square of the chessboard.\n" +
         "This is the black pawn's place. \n", 3)
