#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "trees";
    items[1] = "The trees consist of oaks and other warm climate trees";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/snail");
        move_object(monster, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/path2","west",
"wizards/nalle/area/darvpath","east",
"In the middle of the forest",
"You are in the middle of the forest. Small animals have made nests in the trees\n" +
"atmosphere is very comfortable. Small blueberry bushes cover the ground and.\n" +
"you can also spot glimpses of wild strawberry bushes too. The forest gets \n" +
"You can see the tower to your east but there is an impassable swap between \n" +
"where you are located and the tower. You will have to forget about going \n" +
"there right now. There is a murky swamp to the east.\n", 3)
