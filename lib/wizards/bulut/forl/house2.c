#include "room.h"

object hobbit;

extra_reset() {
        if (!hobbit || !living(hobbit)) {
hobbit = clone_object("/wizards/bulut/forl/monsters/gardener.c");
        move_object(hobbit, this_object());
      }
}
#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();
TWO_EXIT("wizards/bulut/forl/road7","out",
"wizards/bulut/forl/cellar1","down",
"In a house",
"You are standing inside of small house.\n" +
"A Staircase is here, leading down to other room.\n" , 2)
