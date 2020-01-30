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

EIGHT_EXIT("wizards/walla/chessboard/77", "east",
         "wizards/walla/chessboard/66","north",
         "wizards/walla/chessboard/86", "south",
         "wizards/walla/chessboard/67", "northeast",
         "wizards/walla/chessboard/87","southeast",
         "wizards/walla/chessboard/75","west",
         "wizards/walla/chessboard/65","northwest",
         "wizards/walla/chessboard/67","southwest",
"On a black square in the chessboard",
         "You are on a black square of the chessboard.\n" +
         "This is the black pawn's place. \n", 3)
