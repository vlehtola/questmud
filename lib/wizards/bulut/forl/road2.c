#include "room.h"
object hobbit;

extra_reset() {
        if (!hobbit || !living(hobbit)) {
hobbit = clone_object("/wizards/bulut/forl/monsters/hcitizen.c");
        move_object(hobbit, this_object());
      }
}
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

TWO_EXIT("wizards/bulut/forl/road1","south",
"wizards/bulut/forl/road3","north",
"On a road to village",
"You are standing at a road in Forlindon village.\n" +
"Sandy road continues to north and south from here.\n", 3)
