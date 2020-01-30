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

EIGHT_EXIT("wizards/walla/chessboard/28", "east",
         "wizards/walla/chessboard/17","north",
         "wizards/walla/chessboard/37", "south",
         "wizards/walla/chessboard/18", "northeast",
         "wizards/walla/chessboard/38","southeast",
         "wizards/walla/chessboard/26","west",
         "wizards/walla/chessboard/16","northwest",
         "wizards/walla/chessboard/36","southwest",
"On a black square in the chessboard",
         "You are on a black square of the chessboard.\n" +
         "This is the white pawn's place. \n", 3)
