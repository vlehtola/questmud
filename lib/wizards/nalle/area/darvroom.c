#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster,monster2,monster3;

extra_reset() {
    items = allocate(2);
    items[0] = "stairway";
    items[1] = "All you can see is darkness";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/firedarvox");
        move_object(monster, this_object());
    }
    if (!monster2) {
        monster2 = clone_object("/wizards/nalle/area/monsters/icedarvox");
        move_object(monster2, this_object());
    }
if (!monster3) {
        monster3 = clone_object("/wizards/nalle/area/monsters/earthdarvox");
        move_object(monster3, this_object());
    }
}

FIVE_EXIT("wizards/nalle/area/darvroomu","up",
"wizards/nalle/area/darvrooms","south",
"wizards/nalle/area/darvroomn","north",
"wizards/nalle/area/darvroomw","west",
"wizards/nalle/area/darvroome","east",
"Darvox's workroom.",
"Small spheres in the ceiling create an eerie light in this room.\n" +
"This room is almost empty, but there are rooms in every directions,\n" +
"where all the work seems to be done. Three blood-red thrones stand\n" +
"the middle of the room.\n", 3)
