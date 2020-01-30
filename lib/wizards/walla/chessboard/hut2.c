#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object monster,monster2;

extra_reset() {
    set_not_out(3);

    if (!monster) {
        monster = clone_object("/wizards/walla/chessboard/monsters/kasparov");
        move_object(monster, this_object());
    }

if (!monster2) {
        monster2 = clone_object("/wizards/walla/chessboard/monsters/deepblue");
        move_object(monster2, this_object());
    }
}

ONE_EXIT("wizards/walla/chessboard/68", "out",
         "This is the hut of chessplaying",
         "This is a hut where Garry Kasparov and Deep Blue, the IBM machine sits and plays\n" +
         "this noble game called Chess. They both look very concentrated in their game.\n", 3)

