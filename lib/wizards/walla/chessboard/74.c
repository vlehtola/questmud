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

EIGHT_EXIT("wizards/walla/chessboard/75", "east",
         "wizards/walla/chessboard/64","north",
         "wizards/walla/chessboard/84", "south",
         "wizards/walla/chessboard/65", "northeast",
         "wizards/walla/chessboard/85","southeast",
         "wizards/walla/chessboard/73","west",
         "wizards/walla/chessboard/63","northwest",
         "wizards/walla/chessboard/65","southwest",
"On a black square in the chessboard",
         "You are on a black of the chessboard.\n" +
         "This is the black pawn's place. \n", 3)
