#include "room.h"

object troll;
object troll2;

extra_reset() {
        if (!troll || !living(troll)) {
troll = clone_object("/wizards/bulut/forest/troll.c");
        move_object(troll, this_object());

              }

        if (!troll2 || !living(troll2)) {
troll2 = clone_object("/wizards/bulut/forest/troll.c");
        move_object(troll2, this_object());

              }

}


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();


TWO_EXIT("wizards/bulut/forest/forest11","west",
"wizards/bulut/forest/forest2","east",
"On a road",
"You are standing on a little path, leading to troll village.\n" +
"Path continues to east and west from here.\n", 1)
