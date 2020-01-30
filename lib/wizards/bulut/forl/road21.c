#include "room.h"
object rabbit;

extra_reset() {
if (!rabbit || !living(rabbit)) {
rabbit = clone_object("/wizards/bulut/forl/monsters/rabbit.c");
move_object(rabbit, this_object());

      }
}
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

TWO_EXIT("wizards/bulut/forl/road20","south",
"wizards/bulut/forl/road22.c","north",
"On a road in village",
"Sandy road continues to north and south from here.\n", 3)
