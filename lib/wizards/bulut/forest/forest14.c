#include "room.h"

object troll;
object troll2;
object troll3;

extra_reset() {
        if (!troll || !living(troll)) {
troll = clone_object("/wizards/bulut/forest/troll.c");
        move_object(troll, this_object());

              }

        if (!troll2 || !living(troll2)) {
troll2 = clone_object("/wizards/bulut/forest/troll.c");
        move_object(troll2, this_object());

              }


        if (!troll3 || !living(troll3)) {
troll3 = clone_object("/wizards/bulut/forest/troll.c");
        move_object(troll3, this_object());

              }


}

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();


ONE_EXIT("wizards/bulut/forest/forest13","east",
"In the troll village",
"You are standing in the troll village.\n" +
"Path goest back to west from here.\n", 1)
