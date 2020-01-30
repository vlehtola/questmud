#include "room.h"
object guard;

extra_reset() {
        if (!guard || !living(guard)) {
guard = clone_object("/wizards/bulut/forl/monsters/hguard.c");
        move_object(guard, this_object());
      }
}
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

FOUR_EXIT("wizards/bulut/forl/road2","south",
"wizards/bulut/forl/house1","enter",
"wizards/bulut/forl/road4","west",
"wizards/bulut/forl/road5","east",
"On a road in village",
"A sandy road continues from west to east and south.\n" ,3)
