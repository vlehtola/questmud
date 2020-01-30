#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "chair";
    items[1] = "A small satin chair is located in the northeastern corner of the room.\n" +
               "A name has been carved on the chair's surface: Bernard";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/bernard");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/sewer1","east",
"The thieves' meeting place",
"This is rather pleasant place compared to the entrance. This is where\n" +
"the thieves of Chamron come to buy their equipment and exchange stories.\n" +
"The room seems empty, except for the northeastern corner where stands a\n" +
"beautiful, but small satin chair. There is a tunnel leading back to the\n" +
"entrance.\n", 3)

