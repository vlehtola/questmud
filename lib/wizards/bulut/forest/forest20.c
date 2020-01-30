#include "room.h"

object wolf;
object snake;

extra_reset() {
        if (!wolf || !living(wolf)) {
wolf = clone_object("/wizards/bulut/forest/wolf.c");
        move_object(wolf, this_object());

              }

        if (!snake || !living(snake)) {
snake = clone_object("/wizards/bulut/forest/snake.c");
        move_object(snake, this_object());

              }

}


#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();


TWO_EXIT("wizards/bulut/forest/foresta","north",
"wizards/bulut/forest/forest2","west",
"In the forest",
"Path continues to north and west from here.\n", 1)
