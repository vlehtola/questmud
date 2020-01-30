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

EIGHT_EXIT("wizards/walla/chessboard/24", "east",
         "wizards/walla/chessboard/13","north",
         "wizards/walla/chessboard/33", "south",
         "wizards/walla/chessboard/14", "northeast",
         "wizards/walla/chessboard/34","southeast",
         "wizards/walla/chessboard/22","west",
         "wizards/walla/chessboard/12","northwest",
         "wizards/walla/chessboard/32","southwest",
"On a black square in the chessboard",
         "You are on a black square of the chessboard.\n" +
         "This is the white pawn's place. \n", 3)