#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/walla/chessboard/monsters/wking");
        move_object(monster, this_object());
    }
}

FIVE_EXIT("wizards/walla/chessboard/14", "west",
         "wizards/walla/chessboard/16","east",
         "wizards/walla/chessboard/25", "south",
         "wizards/walla/chessboard/24", "southwest",
         "wizards/walla/chessboard/26","southeast",
         "On a white square in the chessboard",
         "You are on a white square of the chessboard.\n" +
         "This is the white king's place. \n", 3)
