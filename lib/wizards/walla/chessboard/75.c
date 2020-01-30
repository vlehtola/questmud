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

EIGHT_EXIT("wizards/walla/chessboard/76", "east",
         "wizards/walla/chessboard/65","north",
         "wizards/walla/chessboard/85", "south",
         "wizards/walla/chessboard/66", "northeast",
         "wizards/walla/chessboard/86","southeast",
         "wizards/walla/chessboard/74","west",
         "wizards/walla/chessboard/64","northwest",
         "wizards/walla/chessboard/66","southwest",
"On a white square in the chessboard",
         "You are on a white square of the chessboard.\n" +
         "This is the black pawn's place. \n", 3)
