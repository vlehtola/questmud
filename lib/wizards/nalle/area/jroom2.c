#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster,monster2,monster3;

extra_reset() {
    items = allocate(2);
    items[0] = "path";
    items[1] = "The path is very thin and scarcely visible";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/pudding2");
        move_object(monster, this_object());
    }
    if (!monster2) {
        monster2 = clone_object("/wizards/nalle/area/monsters/pudding");
        move_object(monster2, this_object());
    }
if (!monster3) {
        monster3 = clone_object("/wizards/nalle/area/monsters/pudding2");
        move_object(monster3, this_object());
    }
}

TWO_EXIT("wizards/nalle/area/jroom3","east",
"wizards/nalle/area/jroom1","southwest",
"A path.",
"A scarcely visible path in the thickets. The terrain is very hard to\n" +
"move in here. Some rattling noises can be heard behind the bushes,\n" +
"which surround you.\n", 3)
