#include "room.h"

object wolf;
object snake2;

extra_reset() {
        if (!wolf || !living(wolf)) {
wolf = clone_object("/wizards/bulut/forest/wolf.c");
        move_object(wolf, this_object());

              }

        if (!snake2 || !living(snake2)) {
snake2 = clone_object("/wizards/bulut/forest/snake.c");
        move_object(snake2, this_object());

              }


}


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();


TWO_EXIT("wizards/bulut/forest/forest7","east",
"wizards/bulut/forest/forest5","west",
"In the crossing",
"You are standing on a little path.\n" +
"Path continues to west and east from here.\n", 1)
