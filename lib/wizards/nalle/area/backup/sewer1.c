#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "tunnel";
    items[1] = "It's a large dirty tunnel.";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/elmore");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/tie22","up",
"wizards/nalle/area/sewer2","west",
"In the sewer system.",
"You are now in the sewer system of Chamron. There is a very unpleasant smell\n" +
"here and you are up to your ankles in mud and slime. There also seems to be \n" +
"quite a large variety of non-vertebral animals living in this part of the sewers.\n" +
"There is a tunnel leading west, but a tall man is sitting on a chair in front of it. \n", 3)

