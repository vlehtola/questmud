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

EIGHT_EXIT("wizards/walla/chessboard/74", "east",
         "wizards/walla/chessboard/63","north",
         "wizards/walla/chessboard/83", "south",
         "wizards/walla/chessboard/64", "northeast",
         "wizards/walla/chessboard/84","southeast",
         "wizards/walla/chessboard/72","west",
         "wizards/walla/chessboard/62","northwest",
         "wizards/walla/chessboard/64","southwest",
"On a white square in the chessboard",
         "You are on a white of the chessboard.\n" +
         "This is the black pawn's place. \n", 3)
