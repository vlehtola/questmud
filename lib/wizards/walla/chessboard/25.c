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

EIGHT_EXIT("wizards/walla/chessboard/26", "east",
         "wizards/walla/chessboard/15","north",
         "wizards/walla/chessboard/35", "south",
         "wizards/walla/chessboard/16", "northeast",
         "wizards/walla/chessboard/36","southeast",
         "wizards/walla/chessboard/24","west",
         "wizards/walla/chessboard/14","northwest",
         "wizards/walla/chessboard/34","southwest",
"On a black square in the chessboard",
         "You are on a black square of the chessboard.\n" +
         "This is the white pawn's place. \n", 3)
