#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

object monster;

extra_reset() {
    items = allocate(2);
    items[0] = "throne";
    items[1] = "A tyrannous throne, decorated with skulls";
    if (!monster) {
        monster = clone_object("/wizards/nalle/area/phantomlord");
        move_object(monster, this_object());
    }
}

ONE_EXIT("wizards/nalle/area/towerd3","up",
"A large room.",
"This room is no longer completely dark. There is are torches burning on the\n" +
"walls, making it possible to see. The room is furnished with a blood red throne\n" +
"and a long oaken table. There are some silver plates and goblets, some of  \n" +
"them are still full. \n", 3)
