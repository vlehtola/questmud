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


FOUR_EXIT("wizards/bulut/forest/forest3","north",
"wizards/bulut/forest/forest1","south",
"wizards/bulut/forest/forest20","east",
"wizards/bulut/forest/forest10","west",
"Crossing",
"You are standing on a little path.\n" +
"Path continues to east, west, north and south from here.\n", 1)
