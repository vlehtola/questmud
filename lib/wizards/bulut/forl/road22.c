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

TWO_EXIT("wizards/bulut/forl/road23","east",
"wizards/bulut/forl/road21","south",
"On a road in village",
"Sandy road turns to south and east from here.\n",3)
