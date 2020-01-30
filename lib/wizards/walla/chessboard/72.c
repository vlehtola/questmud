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

EIGHT_EXIT("wizards/walla/chessboard/73", "east",
         "wizards/walla/chessboard/62","north",
         "wizards/walla/chessboard/82", "south",
         "wizards/walla/chessboard/63", "northeast",
         "wizards/walla/chessboard/83","southeast",
         "wizards/walla/chessboard/71","west",
         "wizards/walla/chessboard/61","northwest",
         "wizards/walla/chessboard/63","southwest",
"On a black square in the chessboard",
         "You are on a black of the chessboard.\n" +
         "This is the black pawn's place. \n", 3)
