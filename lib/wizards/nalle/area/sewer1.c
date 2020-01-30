#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "tunnel";
    items[1] = "The tunnel leading to west is large-sized and very dirty";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/elmore");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/tie22","up",
"wizards/nalle/area/sewer2","west",
"In the sewer system",
"You are now in the sewer system of Chamron. There is very unpleasant\n" +
"smell in here and you are up to your ankles in mud and slime. There\n" +
"seems to be quite large variety of non-vertebral animals living in\n" +
"this part of the sewers. There seems to be a tunnel leading onwards\n" +
"to the west.\n", 3)

